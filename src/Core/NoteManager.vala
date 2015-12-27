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

namespace Keep.Core {

    public class NoteManager {

        public Note[] notes;
        public int current_note;
        public int last_selected_note = 0;

        //signals
        public signal void done_loading ();
        public signal void note_changed (int i);

        public NoteManager () {
            load_notes ();
            set_current_note (0);
        }

        private void load_notes () {
            notes = database_manager.load_all_notes ();
            done_loading ();
        }

        public void set_current_note (int i) {
            last_selected_note = current_note;
            current_note = i;
            note_changed (i);
        }

        public Note get_note (int i) {
            return notes[i];
        }

        public Note get_current_note () {
            return get_note (current_note);
        }

        public void delete_note (int i) {
            database_manager.delete_note (notes[i]);
            load_notes ();
        }
    }
}
