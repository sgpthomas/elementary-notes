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
using Keep.Core;

namespace Keep.Widgets {

    public class Editor : Gtk.SourceView {

        //current note
        private Note current_note;

        //signals
        public signal void note_changed ();

        public Editor (Note note) {

            //create buffer
            //buffer = new SourceBuffer (tagtable);
            this.set_buffer (note);
            message (note.get_id ().to_string ());

            //some source view settings
            this.set_wrap_mode (Gtk.WrapMode.WORD_CHAR);
            smart_home_end = SourceSmartHomeEndType.AFTER;
            this.margin = 5;
        }

        public void load (int i) {
            message (i.to_string ());
            this.set_current_note (note_manager.notes[i]);
            //database_manager.load_note (i+1, notes[i]);
        }

        private void set_current_note (Note note) {
            this.current_note = note;
            this.set_buffer (note);
            message ("Changed note");
        }

        public void save () {
            this.current_note.save ();
        }
    }
}
