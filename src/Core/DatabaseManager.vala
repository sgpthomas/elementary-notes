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

namespace Keep.Core {

    public class DatabaseManager {

        private Database database; //database

        //signals
        public signal void changed ();

        public DatabaseManager () {
            load_databases.begin ((a, b) => {
                message ("Database Manager Initalized");
            });
        }

        public async void load_databases () {
            //make data directory if doesn't already exist
            var data_dir_path = Path.build_filename (Environment.get_user_data_dir (), Constants.GETTEXT_PACKAGE);
            var data_dir = File.new_for_path (data_dir_path);
            if (!data_dir.query_exists ()) { //directory doesn't exist
                try {
                    data_dir.make_directory ();
                } catch (Error e) {
                    error (e.message);
                }
            }

            var db_name = "keep.db";
            //var db_file = File.new_for_path (Path.build_filename (data_dir_path, db_name));
            database = new Database (Path.build_filename (data_dir_path, db_name));

        }

        public void new_note () {
            var data = get_database ();
            data.new_note (true);
            changed ();
        }

        public void save_note (int note_id, uint8[] content) {
            var data = get_database ();
            if (data.note_exists (note_id)) {
                data.update_note (note_id, content);
            } else {
                critical ("Note Doesn't Exist");
            }
            //changed ();
        }

        public void load_note (Note note) {
            var data = get_database ();
            if (data.note_exists (note.get_id ())) {
                data.load_note (note.get_id (), note);
            }
            changed ();
        }

        public Note[] load_all_notes () {
            var data = get_database ();
            return data.load_all_notes ();;
        }

        public void delete_note (Note note) {
            var data = get_database ();
            if (data.note_exists (note.get_id ())) {
                data.delete_note (note);
            }
            changed ();
        }

        private Database get_database () {
            return database;
        }
    }
}
