/* Copyright 2015 Sam Thomas
*
* This file is part of Keep.
*
* Keep is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Keep is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with Keep. If not, see http://www.gnu.org/licenses/.
*/

using Gtk;
using Sqlite;

namespace Keep.Core {

    public class Database {

        private static string NEW_DATABASE = """
        CREATE TABLE Notes (
            id      INTEGER PRIMARY KEY AUTOINCREMENT,
			time    TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
			title   TEXT                                NOT NULL,
            content BLOB                                ,
            sync    INTEGER                             NOT NULL
		);
        """;

        private static string INSERT_NEW = "INSERT INTO Notes (title, content, sync) VALUES ('Untitled', $CONTENT, %i);";

        private static string RESET_DATABASE = """
        DROP TABLE Notes;
        """;

        public string db_path {public get; private set;} //database file

        //error vars
        private int err;
        private string errmsg;

        public Database (string path) {
            this.db_path = path;

            init_database ();
        }

        private void init_database () {
            message ("Initializing Database: %s".printf (db_path));

            //create file object
            exec_command (NEW_DATABASE);
        }

        public Note new_note (bool sync) {
            var sql_string = INSERT_NEW.printf ((sync ? 1 : 0));
            message (sql_string);

            Sqlite.Database db;
            err = Sqlite.Database.open (db_path, out db);

            //check to see if database opening was successful
            if (err != Sqlite.OK) {
                critical ("Error opening database: " + db_path);
            }

            Statement q;
            var i = db.prepare_v2 (sql_string, sql_string.length, out q);
            if (i != Sqlite.OK) {
                critical (db.errmsg ());
            }

            int param_position = q.bind_parameter_index ("$CONTENT");
	        assert (param_position > 0);

            q.bind_null (param_position);

            var rc = q.step();
			if (rc != Sqlite.DONE) {
				critical (db.errmsg ());
			}

            q.reset ();

            message (db.last_insert_rowid ().to_string ());
            return new Note ((int) db.last_insert_rowid ());
        }

        public void update_note (int id, uint8[] content) {
            var sql_seq = "UPDATE Notes SET content=$BLOB WHERE id=%i;".printf (id);
            message (sql_seq);

            Sqlite.Database db;
            err = Sqlite.Database.open (db_path, out db);

            //check to see if database opening was successful
            if (err != Sqlite.OK) {
                critical ("Error opening database: " + db_path);
            }

            Statement q;
            var i = db.prepare_v2 (sql_seq, sql_seq.length, out q);
            if (i != Sqlite.OK) {
                critical (db.errmsg ());
            }

            int param_position = q.bind_parameter_index ("$BLOB");
            message (param_position.to_string ());
	        assert (param_position > 0);

            var blob_size = 0;
            foreach (int a in content) {
                blob_size += (int) sizeof (uint8);
            }

            q.bind_blob (param_position, content, blob_size);


            var rc = q.step();
			if (rc != Sqlite.DONE) {
				critical (db.errmsg ());
			}

            q.reset ();
            message ("Note Updated");
        }

        public bool note_exists (int id) {
            string sql_seq = "SELECT id FROM Notes WHERE id = %i;".printf (id);
            message (sql_seq);

            Sqlite.Database db;
            err = Sqlite.Database.open (db_path, out db);

            //check to see if database opening was successful
            if (err != Sqlite.OK) {
                critical ("Error opening database: " + db_path);
            }

            Statement s;
            var e = db.prepare_v2 (sql_seq, sql_seq.length, out s);
            if (e != Sqlite.OK) {
                critical (db.errmsg ());
            }

            return s.step () == Sqlite.ROW;
        }

        public void load_note (int id, Note note) {
            string sql_seq = "SELECT content FROM Notes WHERE id = %i;".printf (id);
            //message (sql_seq);

            Sqlite.Database db;
            err = Sqlite.Database.open (db_path, out db);

            //check to see if database opening was successful
            if (err != Sqlite.OK) {
                critical ("Error opening database: " + db_path);
            }

            Statement s;
            var e = db.prepare_v2 (sql_seq, sql_seq.length, out s);
            if (e != Sqlite.OK) {
                critical (db.errmsg ());
            }

            Gtk.TextIter start, end;
            //Gtk.TextIter end;

            // Clear currently content
            note.get_bounds (out start, out end);
            note.delete_range (start, end);

            note.get_start_iter (out start);

            s.step ();
            try {
                unowned uint8[] content = (uint8[]) s.column_blob (0);
                content.length = s.column_bytes (0);

                note.begin_not_undoable_action ();
                message ("Database");
                note.deserialize (note, note.deformat, start, content);
                note.end_not_undoable_action ();

            } catch (Error e) {
                critical (e.message);
            }

            message ("Note Loaded");
        }

        public Note[] load_all_notes () {
            Note[] notes = {}; //notes array

            var sql_seq = "SELECT * FROM Notes;";

            //prepare database and get sexy statement
            Sqlite.Database db;
            err = Sqlite.Database.open (db_path, out db);

            //check to see if database opening was successful
            if (err != Sqlite.OK) {
                critical ("Error opening database: " + db_path);
            }

            Statement s;
            var e = db.prepare_v2 (sql_seq, sql_seq.length, out s);
            if (e != Sqlite.OK) {
                critical (db.errmsg ());
            }

            //loop through all the rows
            while (s.step () == Sqlite.ROW) {

                var id = s.column_int (0); //id
                var title = s.column_text (2); //title
                //content
                unowned uint8[] content = (uint8[]) s.column_blob (3);
                content.length = s.column_bytes (3);

                message ("%i %s".printf (id, title));
                var n = new Note.with_content (id, title, content);
                notes += n;
            }

            return notes;
        }

        public void delete_note (Note note) {
            var sql_seq = "DELETE FROM Notes WHERE id = %i".printf (note.get_id ());
            message (sql_seq);

            Sqlite.Database db;
            err = Sqlite.Database.open (db_path, out db);

            //check to see if database opening was successful
            if (err != Sqlite.OK) {
                critical ("Error opening database: " + db_path);
            }

            Statement s;
            var e = db.prepare_v2 (sql_seq, sql_seq.length, out s);
            if (e != Sqlite.OK) {
                critical (db.errmsg ());
            }

            s.step ();
        }

        public void reset_database () {
            message ("Reseting Database: %s".printf (db_path));

            exec_command (RESET_DATABASE);
            exec_command (NEW_DATABASE);
        }

        private void exec_command (string command, bool print_err = false) {
            Sqlite.Database db;
            err = Sqlite.Database.open (db_path, out db);

            //check to see if database opening was successful
            if (err != Sqlite.OK) {
                critical ("Error opening database: " + db_path);
            }

            //create file object
            err = db.exec (command, null, out errmsg);
            if (print_err && err != Sqlite.OK) {
                critical (errmsg);
            }
        }
    }
}
