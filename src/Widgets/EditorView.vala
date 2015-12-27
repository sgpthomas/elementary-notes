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

    public class EditorView : Gtk.Box {

        private Box toolbox; //box for placing tool items
        private Button format_text_button;
        private Button check_list_button;
        private Button image_button;

        //editor object
        //private SourceView source_view
        public Editor editor;

        public EditorView () {
            Object (orientation: Orientation.VERTICAL, spacing: 0);
            this.set_size_request (350, 400);

            setup_ui ();

            connect_signals ();

            show_all ();
        }

        private void setup_ui () {
            toolbox = new Box (Orientation.HORIZONTAL, 0); //create horizonal toolbox
            toolbox.border_width = 2;
            this.pack_start (toolbox, false, false, 0);

            //create format text button
            format_text_button = new Button.from_icon_name ("format-text-bold-symbolic", IconSize.SMALL_TOOLBAR);
            format_text_button.set_relief (ReliefStyle.NONE);
            format_text_button.set_tooltip_text (_("Format Text"));
            toolbox.pack_start (format_text_button, false, false, 0);

            //create check list button
            check_list_button = new Button.from_icon_name ("emblem-default-symbolic", IconSize.SMALL_TOOLBAR);
            check_list_button.set_relief (ReliefStyle.NONE);
            check_list_button.set_tooltip_text (_("Check List"));
            toolbox.pack_start (check_list_button, false, false, 0);

            //create check list button
            image_button = new Button.from_icon_name ("camera-photo-symbolic", IconSize.SMALL_TOOLBAR);
            image_button.set_relief (ReliefStyle.NONE);
            image_button.set_tooltip_text (_("Insert Image"));
            toolbox.pack_start (image_button, false, false, 0);

            //editor
            //source_view = new SourceView ();
            //source_view.set_wrap_mode (Gtk.WrapMode.WORD_CHAR);
            //source_view.smart_home_end = SourceSmartHomeEndType.AFTER;
            //source_view.border_width = 2;
            //source_view.margin = 1;

            //Create Editor
            editor = new Editor (note_manager.get_note (note_manager.last_selected_note));
            this.pack_start (editor, true, true, 0);
        }

        private void connect_signals () {
            format_text_button.clicked.connect (() => {
                var popover = new FormatPopover (format_text_button);
                popover.show ();
            });

            check_list_button.clicked.connect (() => {
                message (note_manager.get_current_note ().get_id ().to_string ());
                editor.save ();
            });

            //image_button.clicked.connect (() => {
            //    database_manager.load_note (editor.current_note);
            //});

            note_manager.note_changed.connect ((j) => {
                editor.load (j);
            });
        }
    }
}
