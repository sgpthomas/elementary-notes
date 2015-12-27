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
using Gdk;
using Pango;
using Keep.Widgets;

namespace Keep.Core {

    public class Note : Gtk.SourceBuffer {

        //text properties
        public string title;
        public string summary;
        private int note_id;

        //content and serialization
        public Atom format;
        public Atom deformat;

        //buffer stuffs
        public TextTagTable tagtable;

        public Note (int id) {
            //this.note_id = id; //set id
            this.note_id = id;

            init ();
            setup_tagtable ();
            connect_signals ();
        }

        public Note.with_content (int id, string title, uint8[] content) {
            this.note_id = id;
            this.title = title;

            init ();
            setup_tagtable ();
            connect_signals ();

            TextIter start; //start iter
            this.get_start_iter (out start); //get the start iter

            if (content != null) {
                try {
                    this.begin_not_undoable_action ();
                    this.deserialize (this, deformat, start, content);
                    this.end_not_undoable_action ();
                } catch (Error e) {
                    critical (e.message);
                }
            }

        }

        private void init () {
            format = this.register_serialize_tagset ("default");
            deformat = this.register_deserialize_tagset ("default");
        }

        private void setup_tagtable () {
            //tagtable = new TextTagTable (); //init tag table
            tagtable = this.get_tag_table ();

            var tag = new TextTag ("bold");
            tag.weight = 700;
            tagtable.add (tag);

            tag = new TextTag ("italic");
            tag.style = Pango.Style.ITALIC;
            tagtable.add (tag);

            tag = new TextTag ("underline");
            tag.underline = Underline.SINGLE;
            tagtable.add (tag);

            tag = new TextTag ("error");
            tag.underline = Underline.ERROR;
            tagtable.add (tag);

            tag = new TextTag ("strikethrough");
            tag.strikethrough = true;
            tagtable.add (tag);
        }

        public int get_id () {
            return note_id;
        }

        public void save () {
            TextIter start, end;
            this.get_bounds (out start, out end);
            uint8 [] content = this.serialize (this, format, start, end);
            database_manager.save_note (note_id, content);
        }

        private void generate_summary () {
            
        }

        private void connect_signals () {
            /*this.changed.connect (() => {

            });*/
        }

    }
}
