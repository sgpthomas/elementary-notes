/* StyleManager.c generated by valac 0.28.1, the Vala compiler
 * generated from StyleManager.vala, do not modify */

/* Copyright 2015 Sam Thomas
*
* This file is part of Hourglass.
*
* Hourglass is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Hourglass is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with Hourglass. If not, see http://www.gnu.org/licenses/.
*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gobject/gvaluecollector.h>


#define KEEP_SERVICES_TYPE_STYLE_MANAGER (keep_services_style_manager_get_type ())
#define KEEP_SERVICES_STYLE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KEEP_SERVICES_TYPE_STYLE_MANAGER, KeepServicesStyleManager))
#define KEEP_SERVICES_STYLE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KEEP_SERVICES_TYPE_STYLE_MANAGER, KeepServicesStyleManagerClass))
#define KEEP_SERVICES_IS_STYLE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KEEP_SERVICES_TYPE_STYLE_MANAGER))
#define KEEP_SERVICES_IS_STYLE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KEEP_SERVICES_TYPE_STYLE_MANAGER))
#define KEEP_SERVICES_STYLE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KEEP_SERVICES_TYPE_STYLE_MANAGER, KeepServicesStyleManagerClass))

typedef struct _KeepServicesStyleManager KeepServicesStyleManager;
typedef struct _KeepServicesStyleManagerClass KeepServicesStyleManagerClass;
typedef struct _KeepServicesStyleManagerPrivate KeepServicesStyleManagerPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _KeepServicesParamSpecStyleManager KeepServicesParamSpecStyleManager;

struct _KeepServicesStyleManager {
	GTypeInstance parent_instance;
	volatile int ref_count;
	KeepServicesStyleManagerPrivate * priv;
};

struct _KeepServicesStyleManagerClass {
	GTypeClass parent_class;
	void (*finalize) (KeepServicesStyleManager *self);
};

struct _KeepServicesParamSpecStyleManager {
	GParamSpec parent_instance;
};


static gpointer keep_services_style_manager_parent_class = NULL;

gpointer keep_services_style_manager_ref (gpointer instance);
void keep_services_style_manager_unref (gpointer instance);
GParamSpec* keep_services_param_spec_style_manager (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void keep_services_value_set_style_manager (GValue* value, gpointer v_object);
void keep_services_value_take_style_manager (GValue* value, gpointer v_object);
gpointer keep_services_value_get_style_manager (const GValue* value);
GType keep_services_style_manager_get_type (void) G_GNUC_CONST;
enum  {
	KEEP_SERVICES_STYLE_MANAGER_DUMMY_PROPERTY
};
void keep_services_style_manager_add_stylesheet (const gchar* path);
#define CONSTANTS_PKG_DATADIR "/usr/share/keep"
KeepServicesStyleManager* keep_services_style_manager_new (void);
KeepServicesStyleManager* keep_services_style_manager_construct (GType object_type);
static void keep_services_style_manager_finalize (KeepServicesStyleManager* obj);


void keep_services_style_manager_add_stylesheet (const gchar* path) {
	gchar* css_file = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	GtkCssProvider* provider = NULL;
	GtkCssProvider* _tmp2_ = NULL;
	GError * _inner_error_ = NULL;
#line 25 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	g_return_if_fail (path != NULL);
#line 26 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	_tmp0_ = path;
#line 26 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	_tmp1_ = g_strconcat (CONSTANTS_PKG_DATADIR "/", _tmp0_, NULL);
#line 26 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	css_file = _tmp1_;
#line 27 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	_tmp2_ = gtk_css_provider_new ();
#line 27 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	provider = _tmp2_;
#line 101 "StyleManager.c"
	{
		GdkScreen* _tmp3_ = NULL;
#line 29 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		gtk_css_provider_load_from_path (provider, css_file, &_inner_error_);
#line 29 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 108 "StyleManager.c"
			goto __catch3_g_error;
		}
#line 30 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		_tmp3_ = gdk_screen_get_default ();
#line 30 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		gtk_style_context_add_provider_for_screen (_tmp3_, (GtkStyleProvider*) provider, (guint) GTK_STYLE_PROVIDER_PRIORITY_USER);
#line 31 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_message ("StyleManager.vala:31: Loaded %s", css_file);
#line 117 "StyleManager.c"
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError* e = NULL;
		const gchar* _tmp4_ = NULL;
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		e = _inner_error_;
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		_inner_error_ = NULL;
#line 33 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		_tmp4_ = e->message;
#line 33 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_error ("StyleManager.vala:33: Error with stylesheet: %s", _tmp4_);
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		_g_error_free0 (e);
#line 134 "StyleManager.c"
	}
	__finally3:
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		_g_object_unref0 (provider);
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		_g_free0 (css_file);
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_clear_error (&_inner_error_);
#line 28 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		return;
#line 149 "StyleManager.c"
	}
#line 25 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	_g_object_unref0 (provider);
#line 25 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	_g_free0 (css_file);
#line 155 "StyleManager.c"
}


KeepServicesStyleManager* keep_services_style_manager_construct (GType object_type) {
	KeepServicesStyleManager* self = NULL;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	self = (KeepServicesStyleManager*) g_type_create_instance (object_type);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return self;
#line 165 "StyleManager.c"
}


KeepServicesStyleManager* keep_services_style_manager_new (void) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return keep_services_style_manager_construct (KEEP_SERVICES_TYPE_STYLE_MANAGER);
#line 172 "StyleManager.c"
}


static void keep_services_value_style_manager_init (GValue* value) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	value->data[0].v_pointer = NULL;
#line 179 "StyleManager.c"
}


static void keep_services_value_style_manager_free_value (GValue* value) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (value->data[0].v_pointer) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		keep_services_style_manager_unref (value->data[0].v_pointer);
#line 188 "StyleManager.c"
	}
}


static void keep_services_value_style_manager_copy_value (const GValue* src_value, GValue* dest_value) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (src_value->data[0].v_pointer) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		dest_value->data[0].v_pointer = keep_services_style_manager_ref (src_value->data[0].v_pointer);
#line 198 "StyleManager.c"
	} else {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		dest_value->data[0].v_pointer = NULL;
#line 202 "StyleManager.c"
	}
}


static gpointer keep_services_value_style_manager_peek_pointer (const GValue* value) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return value->data[0].v_pointer;
#line 210 "StyleManager.c"
}


static gchar* keep_services_value_style_manager_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (collect_values[0].v_pointer) {
#line 217 "StyleManager.c"
		KeepServicesStyleManager* object;
		object = collect_values[0].v_pointer;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		if (object->parent_instance.g_class == NULL) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 224 "StyleManager.c"
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 228 "StyleManager.c"
		}
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		value->data[0].v_pointer = keep_services_style_manager_ref (object);
#line 232 "StyleManager.c"
	} else {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		value->data[0].v_pointer = NULL;
#line 236 "StyleManager.c"
	}
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return NULL;
#line 240 "StyleManager.c"
}


static gchar* keep_services_value_style_manager_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	KeepServicesStyleManager** object_p;
	object_p = collect_values[0].v_pointer;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (!object_p) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
#line 251 "StyleManager.c"
	}
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (!value->data[0].v_pointer) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		*object_p = NULL;
#line 257 "StyleManager.c"
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		*object_p = value->data[0].v_pointer;
#line 261 "StyleManager.c"
	} else {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		*object_p = keep_services_style_manager_ref (value->data[0].v_pointer);
#line 265 "StyleManager.c"
	}
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return NULL;
#line 269 "StyleManager.c"
}


GParamSpec* keep_services_param_spec_style_manager (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	KeepServicesParamSpecStyleManager* spec;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	g_return_val_if_fail (g_type_is_a (object_type, KEEP_SERVICES_TYPE_STYLE_MANAGER), NULL);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	G_PARAM_SPEC (spec)->value_type = object_type;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return G_PARAM_SPEC (spec);
#line 283 "StyleManager.c"
}


gpointer keep_services_value_get_style_manager (const GValue* value) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, KEEP_SERVICES_TYPE_STYLE_MANAGER), NULL);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return value->data[0].v_pointer;
#line 292 "StyleManager.c"
}


void keep_services_value_set_style_manager (GValue* value, gpointer v_object) {
	KeepServicesStyleManager* old;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, KEEP_SERVICES_TYPE_STYLE_MANAGER));
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	old = value->data[0].v_pointer;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (v_object) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, KEEP_SERVICES_TYPE_STYLE_MANAGER));
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		value->data[0].v_pointer = v_object;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		keep_services_style_manager_ref (value->data[0].v_pointer);
#line 312 "StyleManager.c"
	} else {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		value->data[0].v_pointer = NULL;
#line 316 "StyleManager.c"
	}
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (old) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		keep_services_style_manager_unref (old);
#line 322 "StyleManager.c"
	}
}


void keep_services_value_take_style_manager (GValue* value, gpointer v_object) {
	KeepServicesStyleManager* old;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, KEEP_SERVICES_TYPE_STYLE_MANAGER));
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	old = value->data[0].v_pointer;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (v_object) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, KEEP_SERVICES_TYPE_STYLE_MANAGER));
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		value->data[0].v_pointer = v_object;
#line 341 "StyleManager.c"
	} else {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		value->data[0].v_pointer = NULL;
#line 345 "StyleManager.c"
	}
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (old) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		keep_services_style_manager_unref (old);
#line 351 "StyleManager.c"
	}
}


static void keep_services_style_manager_class_init (KeepServicesStyleManagerClass * klass) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	keep_services_style_manager_parent_class = g_type_class_peek_parent (klass);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	((KeepServicesStyleManagerClass *) klass)->finalize = keep_services_style_manager_finalize;
#line 361 "StyleManager.c"
}


static void keep_services_style_manager_instance_init (KeepServicesStyleManager * self) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	self->ref_count = 1;
#line 368 "StyleManager.c"
}


static void keep_services_style_manager_finalize (KeepServicesStyleManager* obj) {
	KeepServicesStyleManager * self;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, KEEP_SERVICES_TYPE_STYLE_MANAGER, KeepServicesStyleManager);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	g_signal_handlers_destroy (self);
#line 378 "StyleManager.c"
}


GType keep_services_style_manager_get_type (void) {
	static volatile gsize keep_services_style_manager_type_id__volatile = 0;
	if (g_once_init_enter (&keep_services_style_manager_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { keep_services_value_style_manager_init, keep_services_value_style_manager_free_value, keep_services_value_style_manager_copy_value, keep_services_value_style_manager_peek_pointer, "p", keep_services_value_style_manager_collect_value, "p", keep_services_value_style_manager_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (KeepServicesStyleManagerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) keep_services_style_manager_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (KeepServicesStyleManager), 0, (GInstanceInitFunc) keep_services_style_manager_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType keep_services_style_manager_type_id;
		keep_services_style_manager_type_id = g_type_register_fundamental (g_type_fundamental_next (), "KeepServicesStyleManager", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&keep_services_style_manager_type_id__volatile, keep_services_style_manager_type_id);
	}
	return keep_services_style_manager_type_id__volatile;
}


gpointer keep_services_style_manager_ref (gpointer instance) {
	KeepServicesStyleManager* self;
	self = instance;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	g_atomic_int_inc (&self->ref_count);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	return instance;
#line 403 "StyleManager.c"
}


void keep_services_style_manager_unref (gpointer instance) {
	KeepServicesStyleManager* self;
	self = instance;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		KEEP_SERVICES_STYLE_MANAGER_GET_CLASS (self)->finalize (self);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Services/StyleManager.vala"
		g_type_free_instance ((GTypeInstance *) self);
#line 416 "StyleManager.c"
	}
}


