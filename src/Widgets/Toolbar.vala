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

namespace Keep.Widgets {

    public class Toolbar : Gtk.Box {

        //buttons
        public ToggleButton sidebar_toggle_button;
        private Image sidebar_toggle_img_hide;
        private Image sidebar_toggle_img_show;

        private Button new_note_button;
        private Button delete_note_button;

        //search
        private SearchEntry search_entry;

        //signals
        public signal void sidebar_toggled ();
        public signal void new_note_pressed ();
        public signal void delete_note_pressed ();

        //constructor
        public Toolbar () {
            Object (orientation: Orientation.HORIZONTAL, spacing: 0); //initalize self
            //this.border_width = 2;
            //this.margin_bottom = 3;

            setup_ui (); //initalize ui

            connect_signals (); //connect signals

            show_all ();
        }

        private void setup_ui () {
            //sidebar toggle button
            sidebar_toggle_img_hide = new Image.from_icon_name ("pane-hide-symbolic", IconSize.SMALL_TOOLBAR);
            sidebar_toggle_img_show = new Image.from_icon_name ("pane-show-symbolic", IconSize.SMALL_TOOLBAR);
            sidebar_toggle_button = new ToggleButton ();
            sidebar_toggle_button.margin_end = 3;
            sidebar_toggle_button.margin_start = 3;
            sidebar_toggle_button.image = sidebar_toggle_img_hide;
            sidebar_toggle_button.set_tooltip_text (_("Show Notes List"));
            this.pack_start (sidebar_toggle_button, false, false, 0);

            //new note button
            new_note_button = new Button.from_icon_name ("document-new-symbolic", IconSize.SMALL_TOOLBAR);
            new_note_button.margin_end = 3;
            new_note_button.set_tooltip_text (_("New Note"));
            this.pack_start (new_note_button, false, false, 0);

            //delete note button
            delete_note_button = new Button.from_icon_name ("edit-delete-symbolic", IconSize.SMALL_TOOLBAR);
            delete_note_button.margin_end = 3;
            delete_note_button.set_tooltip_text (_("Delete Note"));
            this.pack_start (delete_note_button, false, false, 0);

            //search entry
            search_entry = new SearchEntry ();
            search_entry.set_placeholder_text (_("Search Notes"));
            this.pack_end (search_entry, false, false, 0);

        }

        private void connect_signals () {
            sidebar_toggle_button.toggled.connect (() => {
                message ("sidebar toggled");
                sidebar_toggled ();

                if (sidebar_toggle_button.active) {
                    sidebar_toggle_button.image = sidebar_toggle_img_show;
                    sidebar_toggle_button.set_tooltip_text (_("Hide Notes List"));
                } else {
                    sidebar_toggle_button.image = sidebar_toggle_img_hide;
                    sidebar_toggle_button.set_tooltip_text (_("Show Notes List"));
                }
            });

            new_note_button.clicked.connect (() => {
                message ("new note");
                database_manager.new_note ();
                new_note_pressed ();
            });

            delete_note_button.clicked.connect (() => {
                message ("delete note");
                delete_note_pressed ();
            });
        }
    }
}
