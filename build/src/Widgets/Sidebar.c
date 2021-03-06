/* Sidebar.c generated by valac 0.28.1, the Vala compiler
 * generated from Sidebar.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>


#define KEEP_WIDGETS_TYPE_SIDEBAR (keep_widgets_sidebar_get_type ())
#define KEEP_WIDGETS_SIDEBAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KEEP_WIDGETS_TYPE_SIDEBAR, KeepWidgetsSidebar))
#define KEEP_WIDGETS_SIDEBAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KEEP_WIDGETS_TYPE_SIDEBAR, KeepWidgetsSidebarClass))
#define KEEP_WIDGETS_IS_SIDEBAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KEEP_WIDGETS_TYPE_SIDEBAR))
#define KEEP_WIDGETS_IS_SIDEBAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KEEP_WIDGETS_TYPE_SIDEBAR))
#define KEEP_WIDGETS_SIDEBAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KEEP_WIDGETS_TYPE_SIDEBAR, KeepWidgetsSidebarClass))

typedef struct _KeepWidgetsSidebar KeepWidgetsSidebar;
typedef struct _KeepWidgetsSidebarClass KeepWidgetsSidebarClass;
typedef struct _KeepWidgetsSidebarPrivate KeepWidgetsSidebarPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define KEEP_CORE_TYPE_NOTE_MANAGER (keep_core_note_manager_get_type ())
#define KEEP_CORE_NOTE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KEEP_CORE_TYPE_NOTE_MANAGER, KeepCoreNoteManager))
#define KEEP_CORE_NOTE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KEEP_CORE_TYPE_NOTE_MANAGER, KeepCoreNoteManagerClass))
#define KEEP_CORE_IS_NOTE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KEEP_CORE_TYPE_NOTE_MANAGER))
#define KEEP_CORE_IS_NOTE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KEEP_CORE_TYPE_NOTE_MANAGER))
#define KEEP_CORE_NOTE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KEEP_CORE_TYPE_NOTE_MANAGER, KeepCoreNoteManagerClass))

typedef struct _KeepCoreNoteManager KeepCoreNoteManager;
typedef struct _KeepCoreNoteManagerClass KeepCoreNoteManagerClass;
typedef struct _KeepCoreNoteManagerPrivate KeepCoreNoteManagerPrivate;

#define KEEP_CORE_TYPE_NOTE (keep_core_note_get_type ())
#define KEEP_CORE_NOTE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KEEP_CORE_TYPE_NOTE, KeepCoreNote))
#define KEEP_CORE_NOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KEEP_CORE_TYPE_NOTE, KeepCoreNoteClass))
#define KEEP_CORE_IS_NOTE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KEEP_CORE_TYPE_NOTE))
#define KEEP_CORE_IS_NOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KEEP_CORE_TYPE_NOTE))
#define KEEP_CORE_NOTE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KEEP_CORE_TYPE_NOTE, KeepCoreNoteClass))

typedef struct _KeepCoreNote KeepCoreNote;
typedef struct _KeepCoreNoteClass KeepCoreNoteClass;
typedef struct _KeepCoreNotePrivate KeepCoreNotePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))

#define KEEP_CORE_TYPE_DATABASE_MANAGER (keep_core_database_manager_get_type ())
#define KEEP_CORE_DATABASE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KEEP_CORE_TYPE_DATABASE_MANAGER, KeepCoreDatabaseManager))
#define KEEP_CORE_DATABASE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KEEP_CORE_TYPE_DATABASE_MANAGER, KeepCoreDatabaseManagerClass))
#define KEEP_CORE_IS_DATABASE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KEEP_CORE_TYPE_DATABASE_MANAGER))
#define KEEP_CORE_IS_DATABASE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KEEP_CORE_TYPE_DATABASE_MANAGER))
#define KEEP_CORE_DATABASE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KEEP_CORE_TYPE_DATABASE_MANAGER, KeepCoreDatabaseManagerClass))

typedef struct _KeepCoreDatabaseManager KeepCoreDatabaseManager;
typedef struct _KeepCoreDatabaseManagerClass KeepCoreDatabaseManagerClass;

struct _KeepWidgetsSidebar {
	GtkScrolledWindow parent_instance;
	KeepWidgetsSidebarPrivate * priv;
	GtkListBox* list_box;
};

struct _KeepWidgetsSidebarClass {
	GtkScrolledWindowClass parent_class;
};

struct _KeepCoreNoteManager {
	GTypeInstance parent_instance;
	volatile int ref_count;
	KeepCoreNoteManagerPrivate * priv;
	KeepCoreNote** notes;
	gint notes_length1;
	gint current_note;
	gint last_selected_note;
};

struct _KeepCoreNoteManagerClass {
	GTypeClass parent_class;
	void (*finalize) (KeepCoreNoteManager *self);
};

struct _KeepCoreNote {
	GtkSourceBuffer parent_instance;
	KeepCoreNotePrivate * priv;
	gchar* title;
	gchar* summary;
	GdkAtom format;
	GdkAtom deformat;
	GtkTextTagTable* tagtable;
};

struct _KeepCoreNoteClass {
	GtkSourceBufferClass parent_class;
};


static gpointer keep_widgets_sidebar_parent_class = NULL;
extern KeepCoreNoteManager* keep_note_manager;
extern KeepCoreDatabaseManager* keep_database_manager;

GType keep_widgets_sidebar_get_type (void) G_GNUC_CONST;
enum  {
	KEEP_WIDGETS_SIDEBAR_DUMMY_PROPERTY
};
KeepWidgetsSidebar* keep_widgets_sidebar_new (void);
KeepWidgetsSidebar* keep_widgets_sidebar_construct (GType object_type);
static void keep_widgets_sidebar_setup_ui (KeepWidgetsSidebar* self);
static void keep_widgets_sidebar_load_notes (KeepWidgetsSidebar* self);
static void keep_widgets_sidebar_connect_signals (KeepWidgetsSidebar* self);
gpointer keep_core_note_manager_ref (gpointer instance);
void keep_core_note_manager_unref (gpointer instance);
GParamSpec* keep_core_param_spec_note_manager (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void keep_core_value_set_note_manager (GValue* value, gpointer v_object);
void keep_core_value_take_note_manager (GValue* value, gpointer v_object);
gpointer keep_core_value_get_note_manager (const GValue* value);
GType keep_core_note_manager_get_type (void) G_GNUC_CONST;
GType keep_core_note_get_type (void) G_GNUC_CONST;
static void keep_widgets_sidebar_clear_notes (KeepWidgetsSidebar* self);
gpointer keep_core_database_manager_ref (gpointer instance);
void keep_core_database_manager_unref (gpointer instance);
GParamSpec* keep_core_param_spec_database_manager (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void keep_core_value_set_database_manager (GValue* value, gpointer v_object);
void keep_core_value_take_database_manager (GValue* value, gpointer v_object);
gpointer keep_core_value_get_database_manager (const GValue* value);
GType keep_core_database_manager_get_type (void) G_GNUC_CONST;
static void __lambda5_ (KeepWidgetsSidebar* self);
static void ___lambda5__keep_core_database_manager_changed (KeepCoreDatabaseManager* _sender, gpointer self);
static void __lambda6_ (KeepWidgetsSidebar* self, GtkListBoxRow* row);
void keep_core_note_manager_set_current_note (KeepCoreNoteManager* self, gint i);
static void ___lambda6__gtk_list_box_row_selected (GtkListBox* _sender, GtkListBoxRow* row, gpointer self);
static void keep_widgets_sidebar_finalize (GObject* obj);


KeepWidgetsSidebar* keep_widgets_sidebar_construct (GType object_type) {
	KeepWidgetsSidebar * self = NULL;
	GtkListBox* _tmp0_ = NULL;
#line 32 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	self = (KeepWidgetsSidebar*) g_object_new (object_type, NULL);
#line 33 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_object_set ((GtkWidget*) self, "width-request", 150, NULL);
#line 35 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	keep_widgets_sidebar_setup_ui (self);
#line 37 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	keep_widgets_sidebar_load_notes (self);
#line 39 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	keep_widgets_sidebar_connect_signals (self);
#line 41 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp0_ = self->list_box;
#line 41 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp0_);
#line 42 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	gtk_widget_show_all ((GtkWidget*) self);
#line 32 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	return self;
#line 176 "Sidebar.c"
}


KeepWidgetsSidebar* keep_widgets_sidebar_new (void) {
#line 32 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	return keep_widgets_sidebar_construct (KEEP_WIDGETS_TYPE_SIDEBAR);
#line 183 "Sidebar.c"
}


static void keep_widgets_sidebar_setup_ui (KeepWidgetsSidebar* self) {
	GtkListBox* _tmp0_ = NULL;
	GtkListBox* _tmp1_ = NULL;
	GtkStyleContext* _tmp2_ = NULL;
#line 45 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_return_if_fail (self != NULL);
#line 46 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp0_ = (GtkListBox*) gtk_list_box_new ();
#line 46 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_object_ref_sink (_tmp0_);
#line 46 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_g_object_unref0 (self->list_box);
#line 46 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	self->list_box = _tmp0_;
#line 47 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp1_ = self->list_box;
#line 47 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp2_ = gtk_widget_get_style_context ((GtkWidget*) _tmp1_);
#line 47 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	gtk_style_context_add_class (_tmp2_, "sidebar");
#line 207 "Sidebar.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	return self ? g_object_ref (self) : NULL;
#line 214 "Sidebar.c"
}


static void keep_widgets_sidebar_load_notes (KeepWidgetsSidebar* self) {
	KeepCoreNoteManager* _tmp0_ = NULL;
	KeepCoreNote** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
#line 50 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_return_if_fail (self != NULL);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp0_ = keep_note_manager;
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp1_ = _tmp0_->notes;
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp1__length1 = _tmp0_->notes_length1;
#line 230 "Sidebar.c"
	{
		KeepCoreNote** n_collection = NULL;
		gint n_collection_length1 = 0;
		gint _n_collection_size_ = 0;
		gint n_it = 0;
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		n_collection = _tmp1_;
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		n_collection_length1 = _tmp1__length1;
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		for (n_it = 0; n_it < _tmp1__length1; n_it = n_it + 1) {
#line 242 "Sidebar.c"
			KeepCoreNote* _tmp2_ = NULL;
			KeepCoreNote* n = NULL;
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
			_tmp2_ = _g_object_ref0 (n_collection[n_it]);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
			n = _tmp2_;
#line 249 "Sidebar.c"
			{
				GtkBox* box = NULL;
				GtkBox* _tmp3_ = NULL;
				GtkLabel* title = NULL;
				KeepCoreNote* _tmp4_ = NULL;
				const gchar* _tmp5_ = NULL;
				gchar* _tmp6_ = NULL;
				gchar* _tmp7_ = NULL;
				GtkLabel* _tmp8_ = NULL;
				GtkLabel* _tmp9_ = NULL;
				GtkLabel* _tmp10_ = NULL;
				GtkBox* _tmp11_ = NULL;
				GtkLabel* _tmp12_ = NULL;
				GtkLabel* summary = NULL;
				GtkLabel* _tmp13_ = NULL;
				GtkBox* _tmp14_ = NULL;
				GtkLabel* _tmp15_ = NULL;
				GtkBox* _tmp16_ = NULL;
				GtkStyleContext* _tmp17_ = NULL;
				GtkListBox* _tmp18_ = NULL;
				GtkBox* _tmp19_ = NULL;
#line 54 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp3_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 3);
#line 54 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				g_object_ref_sink (_tmp3_);
#line 54 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				box = _tmp3_;
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp4_ = n;
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp5_ = _tmp4_->title;
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp6_ = g_strdup_printf ("<b>%s</b>", _tmp5_);
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp7_ = _tmp6_;
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp8_ = (GtkLabel*) gtk_label_new (_tmp7_);
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				g_object_ref_sink (_tmp8_);
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp9_ = _tmp8_;
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_g_free0 (_tmp7_);
#line 55 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				title = _tmp9_;
#line 56 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp10_ = title;
#line 56 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				gtk_label_set_use_markup (_tmp10_, TRUE);
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp11_ = box;
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp12_ = title;
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				gtk_box_pack_start (_tmp11_, (GtkWidget*) _tmp12_, TRUE, TRUE, (guint) 0);
#line 58 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp13_ = (GtkLabel*) gtk_label_new ("Summary");
#line 58 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				g_object_ref_sink (_tmp13_);
#line 58 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				summary = _tmp13_;
#line 59 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp14_ = box;
#line 59 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp15_ = summary;
#line 59 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				gtk_box_pack_start (_tmp14_, (GtkWidget*) _tmp15_, TRUE, TRUE, (guint) 0);
#line 60 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp16_ = box;
#line 60 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp17_ = gtk_widget_get_style_context ((GtkWidget*) _tmp16_);
#line 60 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				gtk_style_context_add_class (_tmp17_, "note-list-item");
#line 61 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp18_ = self->list_box;
#line 61 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp19_ = box;
#line 61 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				gtk_list_box_prepend (_tmp18_, (GtkWidget*) _tmp19_);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_g_object_unref0 (summary);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_g_object_unref0 (title);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_g_object_unref0 (box);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_g_object_unref0 (n);
#line 337 "Sidebar.c"
			}
		}
	}
#line 64 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	gtk_widget_show_all ((GtkWidget*) self);
#line 343 "Sidebar.c"
}


static void keep_widgets_sidebar_clear_notes (KeepWidgetsSidebar* self) {
	GtkListBox* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
#line 67 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_return_if_fail (self != NULL);
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp0_ = self->list_box;
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp1_ = gtk_container_get_children ((GtkContainer*) _tmp0_);
#line 356 "Sidebar.c"
	{
		GList* w_collection = NULL;
		GList* w_it = NULL;
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		w_collection = _tmp1_;
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		for (w_it = w_collection; w_it != NULL; w_it = w_it->next) {
#line 364 "Sidebar.c"
			GtkWidget* _tmp2_ = NULL;
			GtkWidget* w = NULL;
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
			_tmp2_ = _g_object_ref0 ((GtkWidget*) w_it->data);
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
			w = _tmp2_;
#line 371 "Sidebar.c"
			{
				GtkWidget* _tmp3_ = NULL;
#line 69 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_tmp3_ = w;
#line 69 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				gtk_widget_destroy (_tmp3_);
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
				_g_object_unref0 (w);
#line 380 "Sidebar.c"
			}
		}
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		_g_list_free0 (w_collection);
#line 385 "Sidebar.c"
	}
}


static void __lambda5_ (KeepWidgetsSidebar* self) {
#line 75 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	keep_widgets_sidebar_clear_notes (self);
#line 76 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	keep_widgets_sidebar_load_notes (self);
#line 395 "Sidebar.c"
}


static void ___lambda5__keep_core_database_manager_changed (KeepCoreDatabaseManager* _sender, gpointer self) {
#line 74 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	__lambda5_ ((KeepWidgetsSidebar*) self);
#line 402 "Sidebar.c"
}


static void __lambda6_ (KeepWidgetsSidebar* self, GtkListBoxRow* row) {
	GtkListBox* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	GList* _tmp2_ = NULL;
	guint _tmp3_ = 0U;
	gboolean _tmp4_ = FALSE;
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp0_ = self->list_box;
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp1_ = gtk_container_get_children ((GtkContainer*) _tmp0_);
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp2_ = _tmp1_;
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp3_ = g_list_length (_tmp2_);
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp4_ = _tmp3_ > ((guint) 0);
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_g_list_free0 (_tmp2_);
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	if (_tmp4_) {
#line 426 "Sidebar.c"
		GtkListBoxRow* _tmp5_ = NULL;
		gint _tmp6_ = 0;
		KeepCoreNoteManager* _tmp7_ = NULL;
		GtkListBoxRow* _tmp8_ = NULL;
		gint _tmp9_ = 0;
#line 81 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		_tmp5_ = row;
#line 81 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		_tmp6_ = gtk_list_box_row_get_index (_tmp5_);
#line 81 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		g_signal_emit_by_name (self, "row-changed", _tmp6_);
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		_tmp7_ = keep_note_manager;
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		_tmp8_ = row;
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		_tmp9_ = gtk_list_box_row_get_index (_tmp8_);
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
		keep_core_note_manager_set_current_note (_tmp7_, _tmp9_);
#line 446 "Sidebar.c"
	}
}


static void ___lambda6__gtk_list_box_row_selected (GtkListBox* _sender, GtkListBoxRow* row, gpointer self) {
#line 79 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	__lambda6_ ((KeepWidgetsSidebar*) self, row);
#line 454 "Sidebar.c"
}


static void keep_widgets_sidebar_connect_signals (KeepWidgetsSidebar* self) {
	KeepCoreDatabaseManager* _tmp0_ = NULL;
	GtkListBox* _tmp1_ = NULL;
#line 73 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_return_if_fail (self != NULL);
#line 74 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp0_ = keep_database_manager;
#line 74 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_signal_connect_object (_tmp0_, "changed", (GCallback) ___lambda5__keep_core_database_manager_changed, self, 0);
#line 79 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_tmp1_ = self->list_box;
#line 79 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_signal_connect_object (_tmp1_, "row-selected", (GCallback) ___lambda6__gtk_list_box_row_selected, self, 0);
#line 471 "Sidebar.c"
}


static void keep_widgets_sidebar_class_init (KeepWidgetsSidebarClass * klass) {
#line 25 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	keep_widgets_sidebar_parent_class = g_type_class_peek_parent (klass);
#line 25 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	G_OBJECT_CLASS (klass)->finalize = keep_widgets_sidebar_finalize;
#line 25 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	g_signal_new ("row_changed", KEEP_WIDGETS_TYPE_SIDEBAR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__INT, G_TYPE_NONE, 1, G_TYPE_INT);
#line 482 "Sidebar.c"
}


static void keep_widgets_sidebar_instance_init (KeepWidgetsSidebar * self) {
}


static void keep_widgets_sidebar_finalize (GObject* obj) {
	KeepWidgetsSidebar * self;
#line 25 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, KEEP_WIDGETS_TYPE_SIDEBAR, KeepWidgetsSidebar);
#line 27 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	_g_object_unref0 (self->list_box);
#line 25 "/home/samthomas/Development/Vala/Keep/src/Widgets/Sidebar.vala"
	G_OBJECT_CLASS (keep_widgets_sidebar_parent_class)->finalize (obj);
#line 498 "Sidebar.c"
}


GType keep_widgets_sidebar_get_type (void) {
	static volatile gsize keep_widgets_sidebar_type_id__volatile = 0;
	if (g_once_init_enter (&keep_widgets_sidebar_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (KeepWidgetsSidebarClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) keep_widgets_sidebar_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (KeepWidgetsSidebar), 0, (GInstanceInitFunc) keep_widgets_sidebar_instance_init, NULL };
		GType keep_widgets_sidebar_type_id;
		keep_widgets_sidebar_type_id = g_type_register_static (gtk_scrolled_window_get_type (), "KeepWidgetsSidebar", &g_define_type_info, 0);
		g_once_init_leave (&keep_widgets_sidebar_type_id__volatile, keep_widgets_sidebar_type_id);
	}
	return keep_widgets_sidebar_type_id__volatile;
}



