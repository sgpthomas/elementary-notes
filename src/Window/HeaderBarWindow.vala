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
using Granite.Widgets;

using Keep.Widgets;
using Keep.Services;
using Keep.Core;

namespace Keep.Window {

    public class HeaderBarWindow : Gtk.Window {

        //organization widgets
        public Box main_box;
        //public Keep.Widgets.Toolbar toolbar;
        public Box content_box;

        //content widgets
        private Revealer sidebar_revealer;
        public Sidebar sidebar;
        public EditorView editorview;

        private KeepHeaderBar toolbar;

        //size
        //private int width;
        //private int height;

        //constructor
        public HeaderBarWindow () {
            //this.title = _("Keep"); //set title
            //this.type_hint = Gdk.WindowTypeHint.NORMAL; //make the dialog behave like a normal window
            this.set_size_request (400,450); //set default size

            //setup some $tyles
            StyleManager.add_stylesheet ("style/elements.css");

            setup_ui (); //initialize the user interface

            connect_signals (); //connect signals

            show_all (); //final show all call to make sure everything shows up
        }

        private void setup_ui () {
            main_box = new Box (Orientation.VERTICAL, 0);
            //main_box.margin_start = 8;
            //main_box.margin_end = 8;

            toolbar = new KeepHeaderBar ();
            toolbar.set_show_close_button (true);

            content_box = new Box (Orientation.HORIZONTAL, 0);
            main_box.pack_start (content_box);

            sidebar_revealer = new Revealer ();
            sidebar_revealer.set_transition_type (RevealerTransitionType.SLIDE_LEFT);
            sidebar_revealer.show_all ();
            sidebar = new Sidebar ();
            sidebar_revealer.margin_end = 0;
            sidebar_revealer.add (sidebar);
            content_box.pack_start (sidebar_revealer, false, false, 0);

            editorview = new EditorView ();
            content_box.pack_start (editorview);

            this.add (main_box);
            this.set_titlebar (toolbar);
        }

        private void connect_signals () {
            toolbar.sidebar_toggled.connect (() => {
                toolbar.sidebar_toggle_button.sensitive = false;
                if (sidebar_revealer.child_revealed) {
                    sidebar_revealer.set_reveal_child (false);
                } else {
                    sidebar_revealer.set_reveal_child (true);
                }

                Timeout.add ((int) sidebar_revealer.get_transition_duration (), redraw);
            });

            //sidebar.row_changed.connect ((i) => {
            //    editorview.open_note (i);
            //});

            toolbar.delete_note_pressed.connect (() => {
                note_manager.delete_note (note_manager.current_note);
            });

            this.check_resize.connect (() => {
                this.queue_draw ();
            });

            //quit the program after the dialog is deleted
            this.delete_event.connect (() => {
                Gtk.main_quit ();
                return true;
            });
        }

        private bool redraw () {
            //this.resize (width, height);
            toolbar.sidebar_toggle_button.sensitive = true;
            return false;
        }
    }
}

/*
var tool_box = new Box (Orientation.VERTICAL, 0);

if (true) {

    //toolbar
    var hbox = new Box (Orientation.HORIZONTAL, 0);
    hbox.margin_bottom = 5;

    var close_img = new Image.from_icon_name ("pane-hide-symbolic", IconSize.SMALL_TOOLBAR);
    var close_button = new ToggleButton ();
    close_button.margin_right = 3;
    close_button.margin_left = 3;
    close_button.image = close_img;

    hbox.pack_start (close_button, false, false, 0);

    var new_toolitem = new ToolItem ();
    new_toolitem.margin_right = 3;
    new_toolitem.margin_left = 3;
    var new_button = new Button.from_icon_name ("document-new-symbolic", IconSize.SMALL_TOOLBAR);
    new_toolitem.add (new_button);

    hbox.pack_start (new_toolitem, false, false, 0);

    var other_toolitem = new ToolItem ();
    other_toolitem.margin_right = 3;
    other_toolitem.margin_left = 3;
    var other_button = new Button.from_icon_name ("edit-delete-symbolic", IconSize.SMALL_TOOLBAR);
    other_toolitem.add (other_button);

    hbox.pack_start (other_toolitem, false, false, 0);

    var search = new SearchEntry ();
    hbox.pack_end (search, false, false, 0);

     // The Pane:
    var main_box = new Box (Orientation.HORIZONTAL, 0);
    main_box.vexpand = true;
    box.pack_start (hbox, false, false, 0);
    box.pack_start (main_box);

    // left
    var frame = new Frame (null);
    var list_box = new ListBox ();
    list_box.width_request = 150;

    for (int i = 0; i < 10; i++) {
        var note = new Box (Orientation.VERTICAL, 3);
        var title = new Label ("<b>Shopping List</b>");
        title.set_use_markup (true);
        note.pack_start (title);
        var sum = new Label ("1 List      3:54p");
        note.pack_start (sum);
        list_box.prepend (note);
    }

    frame.add (list_box);
    main_box.pack_start (frame, false, false, 0);

    // right
    var note_frame = new Frame (null);
    var note_box = new Box (Orientation.VERTICAL, 0);
    note_frame.margin_left = 6;

    var note_tools = new Box (Orientation.HORIZONTAL, 0);
    note_tools.border_width = 1;

    var text_item = new ToolItem ();
    text_item.margin_right = 1;
    text_item.margin_left = 1;
    text_item.margin_top = 1;
    var text_button = new Button.from_icon_name ("format-text-bold-symbolic", IconSize.SMALL_TOOLBAR);
    text_button.set_relief (ReliefStyle.NONE);
    text_item.add (text_button);
    note_tools.pack_start (text_item, false, false, 0);

    var check_item = new ToolItem ();
    check_item.margin_right = 1;
    check_item.margin_left = 1;
    check_item.margin_top = 1;
    var check_button = new Button.from_icon_name ("emblem-default-symbolic", IconSize.SMALL_TOOLBAR);
    check_button.set_relief (ReliefStyle.NONE);
    check_item.add (check_button);
    note_tools.pack_start (check_item, false, false, 0);

    note_box.pack_start (note_tools, false, false, 0);

    note_frame.add (note_box);
    main_box.pack_start (note_frame);
} else {
    var wel = new Welcome ("No Notes", "Start taking some Notes");
    wel.append ("document-new", "New Note", "Write Something Down");
    box.pack_start (wel, true, true);
}
*/
