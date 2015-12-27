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

    public class Sidebar : Gtk.ScrolledWindow {

        public ListBox list_box;

        public signal void row_changed (int i);

        //constructor
        public Sidebar () {
            this.width_request = 150;

            setup_ui (); //initialize the ui

            load_notes (); //load notes

            connect_signals (); //connect signals

            this.add (list_box);
            show_all ();
        }

        private void setup_ui () {
            list_box = new ListBox (); //create list box
            list_box.get_style_context ().add_class ("sidebar");
        }

        private void load_notes () {


            foreach (var n in note_manager.notes) {
                var box = new Box (Orientation.VERTICAL, 3); //box
                var title = new Label ("<b>%s</b>".printf (n.title));
                title.set_use_markup (true);
                box.pack_start (title);
                var summary = new Label ("Summary");
                box.pack_start (summary);
                box.get_style_context ().add_class ("note-list-item");
                list_box.prepend (box);
            }

            show_all ();
        }

        private void clear_notes () {
            foreach (Widget w in list_box.get_children ()) {
                w.destroy ();
            }
        }

        private void connect_signals () {
            database_manager.changed.connect (() => {
                clear_notes ();
                load_notes ();
            });

            list_box.row_selected.connect ((row) => {
                if (list_box.get_children ().length () > 0) {
                    row_changed (row.get_index ()); //fire signal
                    note_manager.set_current_note (row.get_index ());//update note manager
                }
            });
        }
    }
}
