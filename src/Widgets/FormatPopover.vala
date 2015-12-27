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

    public class FormatPopover : Gtk.Popover {

        private Box box;

        //buttons
        private ToggleButton bold_button;
        private ToggleButton italic_button;
        private ToggleButton underline_button;
        private ToggleButton strikethrough_button;

        //signals
        public signal void bold_button_pressed ();
        public signal void italic_button_pressed ();
        public signal void underline_button_pressed ();
        public signal void strikethrough_button_pressed ();

        public FormatPopover (Widget origin) {
            this.set_relative_to (origin); //set relative to origin
            this.set_position (PositionType.BOTTOM);
            this.border_width = 2;
            this.halign = Align.CENTER;

            setup_ui ();

            connect_signals ();

            show_all ();
        }

        private void setup_ui () {
            box = new Box (Orientation.HORIZONTAL, 0); //create main box

            //bold button
            bold_button = new ToggleButton ();
            bold_button.image = new Image.from_icon_name ("format-text-bold-symbolic", IconSize.SMALL_TOOLBAR);
            bold_button.set_tooltip_text (_("Bold"));
            box.pack_start (bold_button, true, false, 0);

            //italic button
            italic_button = new ToggleButton ();
            italic_button.image = new Image.from_icon_name ("format-text-italic-symbolic", IconSize.SMALL_TOOLBAR);
            italic_button.set_tooltip_text (_("Italic"));
            box.pack_start (italic_button, true, false, 0);

            underline_button = new ToggleButton ();
            underline_button.image = new Image.from_icon_name ("format-text-underline-symbolic", IconSize.SMALL_TOOLBAR);
            underline_button.set_tooltip_text (_("Underline"));
            box.pack_start (underline_button, true, false, 0);

            strikethrough_button = new ToggleButton ();
            strikethrough_button.image = new Image.from_icon_name ("format-text-strikethrough-symbolic", IconSize.SMALL_TOOLBAR);
            strikethrough_button.set_tooltip_text (_("Strikethrough"));
            box.pack_start (strikethrough_button, true, false, 0);

            this.add (box);
        }

        private void connect_signals () {
            bold_button.clicked.connect (() => {bold_button_pressed (); });
            italic_button.clicked.connect (() => {italic_button_pressed (); });
            underline_button.clicked.connect (() => {underline_button_pressed (); });
            strikethrough_button.clicked.connect (() => {strikethrough_button_pressed (); });
        }
    }
}
