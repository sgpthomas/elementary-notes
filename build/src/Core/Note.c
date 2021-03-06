/* Note.c generated by valac 0.28.1, the Vala compiler
 * generated from Note.vala, do not modify */

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
#include <gtksourceview/gtksource.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <pango/pango.h>


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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define KEEP_CORE_TYPE_DATABASE_MANAGER (keep_core_database_manager_get_type ())
#define KEEP_CORE_DATABASE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KEEP_CORE_TYPE_DATABASE_MANAGER, KeepCoreDatabaseManager))
#define KEEP_CORE_DATABASE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KEEP_CORE_TYPE_DATABASE_MANAGER, KeepCoreDatabaseManagerClass))
#define KEEP_CORE_IS_DATABASE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KEEP_CORE_TYPE_DATABASE_MANAGER))
#define KEEP_CORE_IS_DATABASE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KEEP_CORE_TYPE_DATABASE_MANAGER))
#define KEEP_CORE_DATABASE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KEEP_CORE_TYPE_DATABASE_MANAGER, KeepCoreDatabaseManagerClass))

typedef struct _KeepCoreDatabaseManager KeepCoreDatabaseManager;
typedef struct _KeepCoreDatabaseManagerClass KeepCoreDatabaseManagerClass;

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

struct _KeepCoreNotePrivate {
	gint note_id;
};


static gpointer keep_core_note_parent_class = NULL;
extern KeepCoreDatabaseManager* keep_database_manager;

GType keep_core_note_get_type (void) G_GNUC_CONST;
#define KEEP_CORE_NOTE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), KEEP_CORE_TYPE_NOTE, KeepCoreNotePrivate))
enum  {
	KEEP_CORE_NOTE_DUMMY_PROPERTY
};
KeepCoreNote* keep_core_note_new (gint id);
KeepCoreNote* keep_core_note_construct (GType object_type, gint id);
static void keep_core_note_init (KeepCoreNote* self);
static void keep_core_note_setup_tagtable (KeepCoreNote* self);
static void keep_core_note_connect_signals (KeepCoreNote* self);
KeepCoreNote* keep_core_note_new_with_content (gint id, const gchar* title, guint8* content, int content_length1);
KeepCoreNote* keep_core_note_construct_with_content (GType object_type, gint id, const gchar* title, guint8* content, int content_length1);
gint keep_core_note_get_id (KeepCoreNote* self);
void keep_core_note_save (KeepCoreNote* self);
gpointer keep_core_database_manager_ref (gpointer instance);
void keep_core_database_manager_unref (gpointer instance);
GParamSpec* keep_core_param_spec_database_manager (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void keep_core_value_set_database_manager (GValue* value, gpointer v_object);
void keep_core_value_take_database_manager (GValue* value, gpointer v_object);
gpointer keep_core_value_get_database_manager (const GValue* value);
GType keep_core_database_manager_get_type (void) G_GNUC_CONST;
void keep_core_database_manager_save_note (KeepCoreDatabaseManager* self, gint note_id, guint8* content, int content_length1);
static void keep_core_note_generate_summary (KeepCoreNote* self);
static void keep_core_note_finalize (GObject* obj);


KeepCoreNote* keep_core_note_construct (GType object_type, gint id) {
	KeepCoreNote * self = NULL;
	gint _tmp0_ = 0;
#line 40 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self = (KeepCoreNote*) g_object_new (object_type, NULL);
#line 42 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp0_ = id;
#line 42 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self->priv->note_id = _tmp0_;
#line 44 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_note_init (self);
#line 45 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_note_setup_tagtable (self);
#line 46 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_note_connect_signals (self);
#line 40 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	return self;
#line 122 "Note.c"
}


KeepCoreNote* keep_core_note_new (gint id) {
#line 40 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	return keep_core_note_construct (KEEP_CORE_TYPE_NOTE, id);
#line 129 "Note.c"
}


KeepCoreNote* keep_core_note_construct_with_content (GType object_type, gint id, const gchar* title, guint8* content, int content_length1) {
	KeepCoreNote * self = NULL;
	gint _tmp0_ = 0;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	GtkTextIter start = {0};
	GtkTextIter _tmp3_ = {0};
	guint8* _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	GError * _inner_error_ = NULL;
#line 49 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_return_val_if_fail (title != NULL, NULL);
#line 49 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self = (KeepCoreNote*) g_object_new (object_type, NULL);
#line 50 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp0_ = id;
#line 50 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self->priv->note_id = _tmp0_;
#line 51 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp1_ = title;
#line 51 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp2_ = g_strdup (_tmp1_);
#line 51 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_free0 (self->title);
#line 51 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self->title = _tmp2_;
#line 53 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_note_init (self);
#line 54 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_note_setup_tagtable (self);
#line 55 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_note_connect_signals (self);
#line 58 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	gtk_text_buffer_get_start_iter ((GtkTextBuffer*) self, &_tmp3_);
#line 58 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	start = _tmp3_;
#line 60 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp4_ = content;
#line 60 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp4__length1 = content_length1;
#line 60 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	if (_tmp4_ != NULL) {
#line 175 "Note.c"
		{
			GdkAtom _tmp5_ = 0U;
			GtkTextIter _tmp6_ = {0};
			guint8* _tmp7_ = NULL;
			gint _tmp7__length1 = 0;
#line 62 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			gtk_source_buffer_begin_not_undoable_action ((GtkSourceBuffer*) self);
#line 63 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_tmp5_ = self->deformat;
#line 63 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_tmp6_ = start;
#line 63 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_tmp7_ = content;
#line 63 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_tmp7__length1 = content_length1;
#line 63 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			gtk_text_buffer_deserialize ((GtkTextBuffer*) self, (GtkTextBuffer*) self, _tmp5_, &_tmp6_, _tmp7_, (gsize) _tmp7__length1, &_inner_error_);
#line 63 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 195 "Note.c"
				goto __catch2_g_error;
			}
#line 64 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			gtk_source_buffer_end_not_undoable_action ((GtkSourceBuffer*) self);
#line 200 "Note.c"
		}
		goto __finally2;
		__catch2_g_error:
		{
			GError* e = NULL;
			GError* _tmp8_ = NULL;
			const gchar* _tmp9_ = NULL;
#line 61 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			e = _inner_error_;
#line 61 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_inner_error_ = NULL;
#line 66 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_tmp8_ = e;
#line 66 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_tmp9_ = _tmp8_->message;
#line 66 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			g_critical ("Note.vala:66: %s", _tmp9_);
#line 61 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			_g_error_free0 (e);
#line 220 "Note.c"
		}
		__finally2:
#line 61 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
		if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 61 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 61 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			g_clear_error (&_inner_error_);
#line 61 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
			return NULL;
#line 231 "Note.c"
		}
	}
#line 49 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	return self;
#line 236 "Note.c"
}


KeepCoreNote* keep_core_note_new_with_content (gint id, const gchar* title, guint8* content, int content_length1) {
#line 49 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	return keep_core_note_construct_with_content (KEEP_CORE_TYPE_NOTE, id, title, content, content_length1);
#line 243 "Note.c"
}


static void keep_core_note_init (KeepCoreNote* self) {
	GdkAtom _tmp0_ = 0U;
	GdkAtom _tmp1_ = 0U;
#line 72 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_return_if_fail (self != NULL);
#line 73 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp0_ = gtk_text_buffer_register_serialize_tagset ((GtkTextBuffer*) self, "default");
#line 73 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self->format = _tmp0_;
#line 74 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp1_ = gtk_text_buffer_register_deserialize_tagset ((GtkTextBuffer*) self, "default");
#line 74 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self->deformat = _tmp1_;
#line 260 "Note.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 79 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	return self ? g_object_ref (self) : NULL;
#line 267 "Note.c"
}


static void keep_core_note_setup_tagtable (KeepCoreNote* self) {
	GtkTextTagTable* _tmp0_ = NULL;
	GtkTextTagTable* _tmp1_ = NULL;
	GtkTextTag* tag = NULL;
	GtkTextTag* _tmp2_ = NULL;
	GtkTextTag* _tmp3_ = NULL;
	GtkTextTagTable* _tmp4_ = NULL;
	GtkTextTag* _tmp5_ = NULL;
	GtkTextTag* _tmp6_ = NULL;
	GtkTextTag* _tmp7_ = NULL;
	GtkTextTagTable* _tmp8_ = NULL;
	GtkTextTag* _tmp9_ = NULL;
	GtkTextTag* _tmp10_ = NULL;
	GtkTextTag* _tmp11_ = NULL;
	GtkTextTagTable* _tmp12_ = NULL;
	GtkTextTag* _tmp13_ = NULL;
	GtkTextTag* _tmp14_ = NULL;
	GtkTextTag* _tmp15_ = NULL;
	GtkTextTagTable* _tmp16_ = NULL;
	GtkTextTag* _tmp17_ = NULL;
	GtkTextTag* _tmp18_ = NULL;
	GtkTextTag* _tmp19_ = NULL;
	GtkTextTagTable* _tmp20_ = NULL;
	GtkTextTag* _tmp21_ = NULL;
#line 77 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_return_if_fail (self != NULL);
#line 79 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp0_ = gtk_text_buffer_get_tag_table ((GtkTextBuffer*) self);
#line 79 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp1_ = _g_object_ref0 (_tmp0_);
#line 79 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_object_unref0 (self->tagtable);
#line 79 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self->tagtable = _tmp1_;
#line 81 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp2_ = gtk_text_tag_new ("bold");
#line 81 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	tag = _tmp2_;
#line 82 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp3_ = tag;
#line 82 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_object_set (_tmp3_, "weight", 700, NULL);
#line 83 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp4_ = self->tagtable;
#line 83 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp5_ = tag;
#line 83 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	gtk_text_tag_table_add (_tmp4_, _tmp5_);
#line 85 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp6_ = gtk_text_tag_new ("italic");
#line 85 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_object_unref0 (tag);
#line 85 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	tag = _tmp6_;
#line 86 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp7_ = tag;
#line 86 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_object_set (_tmp7_, "style", PANGO_STYLE_ITALIC, NULL);
#line 87 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp8_ = self->tagtable;
#line 87 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp9_ = tag;
#line 87 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	gtk_text_tag_table_add (_tmp8_, _tmp9_);
#line 89 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp10_ = gtk_text_tag_new ("underline");
#line 89 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_object_unref0 (tag);
#line 89 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	tag = _tmp10_;
#line 90 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp11_ = tag;
#line 90 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_object_set (_tmp11_, "underline", PANGO_UNDERLINE_SINGLE, NULL);
#line 91 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp12_ = self->tagtable;
#line 91 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp13_ = tag;
#line 91 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	gtk_text_tag_table_add (_tmp12_, _tmp13_);
#line 93 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp14_ = gtk_text_tag_new ("error");
#line 93 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_object_unref0 (tag);
#line 93 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	tag = _tmp14_;
#line 94 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp15_ = tag;
#line 94 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_object_set (_tmp15_, "underline", PANGO_UNDERLINE_ERROR, NULL);
#line 95 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp16_ = self->tagtable;
#line 95 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp17_ = tag;
#line 95 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	gtk_text_tag_table_add (_tmp16_, _tmp17_);
#line 97 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp18_ = gtk_text_tag_new ("strikethrough");
#line 97 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_object_unref0 (tag);
#line 97 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	tag = _tmp18_;
#line 98 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp19_ = tag;
#line 98 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_object_set (_tmp19_, "strikethrough", TRUE, NULL);
#line 99 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp20_ = self->tagtable;
#line 99 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp21_ = tag;
#line 99 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	gtk_text_tag_table_add (_tmp20_, _tmp21_);
#line 77 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_object_unref0 (tag);
#line 385 "Note.c"
}


gint keep_core_note_get_id (KeepCoreNote* self) {
	gint result = 0;
	gint _tmp0_ = 0;
#line 102 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 103 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp0_ = self->priv->note_id;
#line 103 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	result = _tmp0_;
#line 103 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	return result;
#line 400 "Note.c"
}


void keep_core_note_save (KeepCoreNote* self) {
	GtkTextIter start = {0};
	GtkTextIter end = {0};
	GtkTextIter _tmp0_ = {0};
	GtkTextIter _tmp1_ = {0};
	guint8* content = NULL;
	GdkAtom _tmp2_ = 0U;
	GtkTextIter _tmp3_ = {0};
	GtkTextIter _tmp4_ = {0};
	gsize _tmp5_;
	guint8* _tmp6_ = NULL;
	gint content_length1 = 0;
	gint _content_size_ = 0;
	KeepCoreDatabaseManager* _tmp7_ = NULL;
	gint _tmp8_ = 0;
#line 106 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_return_if_fail (self != NULL);
#line 108 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	gtk_text_buffer_get_bounds ((GtkTextBuffer*) self, &_tmp0_, &_tmp1_);
#line 108 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	start = _tmp0_;
#line 108 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	end = _tmp1_;
#line 109 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp2_ = self->format;
#line 109 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp3_ = start;
#line 109 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp4_ = end;
#line 109 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp6_ = gtk_text_buffer_serialize ((GtkTextBuffer*) self, (GtkTextBuffer*) self, _tmp2_, &_tmp3_, &_tmp4_, &_tmp5_);
#line 109 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	content = _tmp6_;
#line 109 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	content_length1 = _tmp5_;
#line 109 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_content_size_ = content_length1;
#line 110 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp7_ = keep_database_manager;
#line 110 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_tmp8_ = self->priv->note_id;
#line 110 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_database_manager_save_note (_tmp7_, _tmp8_, content, content_length1);
#line 106 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	content = (g_free (content), NULL);
#line 449 "Note.c"
}


static void keep_core_note_generate_summary (KeepCoreNote* self) {
#line 113 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_return_if_fail (self != NULL);
#line 456 "Note.c"
}


static void keep_core_note_connect_signals (KeepCoreNote* self) {
#line 117 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_return_if_fail (self != NULL);
#line 463 "Note.c"
}


static void keep_core_note_class_init (KeepCoreNoteClass * klass) {
#line 26 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	keep_core_note_parent_class = g_type_class_peek_parent (klass);
#line 26 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	g_type_class_add_private (klass, sizeof (KeepCoreNotePrivate));
#line 26 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	G_OBJECT_CLASS (klass)->finalize = keep_core_note_finalize;
#line 474 "Note.c"
}


static void keep_core_note_instance_init (KeepCoreNote * self) {
#line 26 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self->priv = KEEP_CORE_NOTE_GET_PRIVATE (self);
#line 481 "Note.c"
}


static void keep_core_note_finalize (GObject* obj) {
	KeepCoreNote * self;
#line 26 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, KEEP_CORE_TYPE_NOTE, KeepCoreNote);
#line 29 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_free0 (self->title);
#line 30 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_free0 (self->summary);
#line 38 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	_g_object_unref0 (self->tagtable);
#line 26 "/home/samthomas/Development/Vala/Keep/src/Core/Note.vala"
	G_OBJECT_CLASS (keep_core_note_parent_class)->finalize (obj);
#line 497 "Note.c"
}


GType keep_core_note_get_type (void) {
	static volatile gsize keep_core_note_type_id__volatile = 0;
	if (g_once_init_enter (&keep_core_note_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (KeepCoreNoteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) keep_core_note_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (KeepCoreNote), 0, (GInstanceInitFunc) keep_core_note_instance_init, NULL };
		GType keep_core_note_type_id;
		keep_core_note_type_id = g_type_register_static (gtk_source_buffer_get_type (), "KeepCoreNote", &g_define_type_info, 0);
		g_once_init_leave (&keep_core_note_type_id__volatile, keep_core_note_type_id);
	}
	return keep_core_note_type_id__volatile;
}



