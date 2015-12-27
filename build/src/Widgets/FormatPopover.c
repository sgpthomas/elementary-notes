/* FormatPopover.c generated by valac 0.28.1, the Vala compiler
 * generated from FormatPopover.vala, do not modify */

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
#include <glib/gi18n-lib.h>


#define KEEP_WIDGETS_TYPE_FORMAT_POPOVER (keep_widgets_format_popover_get_type ())
#define KEEP_WIDGETS_FORMAT_POPOVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), KEEP_WIDGETS_TYPE_FORMAT_POPOVER, KeepWidgetsFormatPopover))
#define KEEP_WIDGETS_FORMAT_POPOVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), KEEP_WIDGETS_TYPE_FORMAT_POPOVER, KeepWidgetsFormatPopoverClass))
#define KEEP_WIDGETS_IS_FORMAT_POPOVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), KEEP_WIDGETS_TYPE_FORMAT_POPOVER))
#define KEEP_WIDGETS_IS_FORMAT_POPOVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), KEEP_WIDGETS_TYPE_FORMAT_POPOVER))
#define KEEP_WIDGETS_FORMAT_POPOVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), KEEP_WIDGETS_TYPE_FORMAT_POPOVER, KeepWidgetsFormatPopoverClass))

typedef struct _KeepWidgetsFormatPopover KeepWidgetsFormatPopover;
typedef struct _KeepWidgetsFormatPopoverClass KeepWidgetsFormatPopoverClass;
typedef struct _KeepWidgetsFormatPopoverPrivate KeepWidgetsFormatPopoverPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _KeepWidgetsFormatPopover {
	GtkPopover parent_instance;
	KeepWidgetsFormatPopoverPrivate * priv;
};

struct _KeepWidgetsFormatPopoverClass {
	GtkPopoverClass parent_class;
};

struct _KeepWidgetsFormatPopoverPrivate {
	GtkBox* box;
	GtkToggleButton* bold_button;
	GtkToggleButton* italic_button;
	GtkToggleButton* underline_button;
	GtkToggleButton* strikethrough_button;
};


static gpointer keep_widgets_format_popover_parent_class = NULL;

GType keep_widgets_format_popover_get_type (void) G_GNUC_CONST;
#define KEEP_WIDGETS_FORMAT_POPOVER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), KEEP_WIDGETS_TYPE_FORMAT_POPOVER, KeepWidgetsFormatPopoverPrivate))
enum  {
	KEEP_WIDGETS_FORMAT_POPOVER_DUMMY_PROPERTY
};
KeepWidgetsFormatPopover* keep_widgets_format_popover_new (GtkWidget* origin);
KeepWidgetsFormatPopover* keep_widgets_format_popover_construct (GType object_type, GtkWidget* origin);
static void keep_widgets_format_popover_setup_ui (KeepWidgetsFormatPopover* self);
static void keep_widgets_format_popover_connect_signals (KeepWidgetsFormatPopover* self);
static void __lambda8_ (KeepWidgetsFormatPopover* self);
static void ___lambda8__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void __lambda9_ (KeepWidgetsFormatPopover* self);
static void ___lambda9__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void __lambda10_ (KeepWidgetsFormatPopover* self);
static void ___lambda10__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void __lambda11_ (KeepWidgetsFormatPopover* self);
static void ___lambda11__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void keep_widgets_format_popover_finalize (GObject* obj);


KeepWidgetsFormatPopover* keep_widgets_format_popover_construct (GType object_type, GtkWidget* origin) {
	KeepWidgetsFormatPopover * self = NULL;
	GtkWidget* _tmp0_ = NULL;
#line 39 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_return_val_if_fail (origin != NULL, NULL);
#line 39 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self = (KeepWidgetsFormatPopover*) g_object_new (object_type, NULL);
#line 40 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp0_ = origin;
#line 40 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_popover_set_relative_to ((GtkPopover*) self, _tmp0_);
#line 41 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_popover_set_position ((GtkPopover*) self, GTK_POS_BOTTOM);
#line 42 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_container_set_border_width ((GtkContainer*) self, (guint) 2);
#line 43 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_widget_set_halign ((GtkWidget*) self, GTK_ALIGN_CENTER);
#line 45 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	keep_widgets_format_popover_setup_ui (self);
#line 47 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	keep_widgets_format_popover_connect_signals (self);
#line 49 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_widget_show_all ((GtkWidget*) self);
#line 39 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	return self;
#line 106 "FormatPopover.c"
}


KeepWidgetsFormatPopover* keep_widgets_format_popover_new (GtkWidget* origin) {
#line 39 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	return keep_widgets_format_popover_construct (KEEP_WIDGETS_TYPE_FORMAT_POPOVER, origin);
#line 113 "FormatPopover.c"
}


static void keep_widgets_format_popover_setup_ui (KeepWidgetsFormatPopover* self) {
	GtkBox* _tmp0_ = NULL;
	GtkToggleButton* _tmp1_ = NULL;
	GtkToggleButton* _tmp2_ = NULL;
	GtkImage* _tmp3_ = NULL;
	GtkImage* _tmp4_ = NULL;
	GtkToggleButton* _tmp5_ = NULL;
	const gchar* _tmp6_ = NULL;
	GtkBox* _tmp7_ = NULL;
	GtkToggleButton* _tmp8_ = NULL;
	GtkToggleButton* _tmp9_ = NULL;
	GtkToggleButton* _tmp10_ = NULL;
	GtkImage* _tmp11_ = NULL;
	GtkImage* _tmp12_ = NULL;
	GtkToggleButton* _tmp13_ = NULL;
	const gchar* _tmp14_ = NULL;
	GtkBox* _tmp15_ = NULL;
	GtkToggleButton* _tmp16_ = NULL;
	GtkToggleButton* _tmp17_ = NULL;
	GtkToggleButton* _tmp18_ = NULL;
	GtkImage* _tmp19_ = NULL;
	GtkImage* _tmp20_ = NULL;
	GtkToggleButton* _tmp21_ = NULL;
	const gchar* _tmp22_ = NULL;
	GtkBox* _tmp23_ = NULL;
	GtkToggleButton* _tmp24_ = NULL;
	GtkToggleButton* _tmp25_ = NULL;
	GtkToggleButton* _tmp26_ = NULL;
	GtkImage* _tmp27_ = NULL;
	GtkImage* _tmp28_ = NULL;
	GtkToggleButton* _tmp29_ = NULL;
	const gchar* _tmp30_ = NULL;
	GtkBox* _tmp31_ = NULL;
	GtkToggleButton* _tmp32_ = NULL;
	GtkBox* _tmp33_ = NULL;
#line 52 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_return_if_fail (self != NULL);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp0_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp0_);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->box);
#line 53 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self->priv->box = _tmp0_;
#line 56 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp1_ = (GtkToggleButton*) gtk_toggle_button_new ();
#line 56 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp1_);
#line 56 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->bold_button);
#line 56 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self->priv->bold_button = _tmp1_;
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp2_ = self->priv->bold_button;
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp3_ = (GtkImage*) gtk_image_new_from_icon_name ("format-text-bold-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp3_);
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp4_ = _tmp3_;
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_button_set_image ((GtkButton*) _tmp2_, (GtkWidget*) _tmp4_);
#line 57 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (_tmp4_);
#line 58 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp5_ = self->priv->bold_button;
#line 58 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp6_ = _ ("Bold");
#line 58 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_widget_set_tooltip_text ((GtkWidget*) _tmp5_, _tmp6_);
#line 59 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp7_ = self->priv->box;
#line 59 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp8_ = self->priv->bold_button;
#line 59 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_box_pack_start (_tmp7_, (GtkWidget*) _tmp8_, TRUE, FALSE, (guint) 0);
#line 62 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp9_ = (GtkToggleButton*) gtk_toggle_button_new ();
#line 62 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp9_);
#line 62 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->italic_button);
#line 62 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self->priv->italic_button = _tmp9_;
#line 63 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp10_ = self->priv->italic_button;
#line 63 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp11_ = (GtkImage*) gtk_image_new_from_icon_name ("format-text-italic-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);
#line 63 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp11_);
#line 63 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp12_ = _tmp11_;
#line 63 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_button_set_image ((GtkButton*) _tmp10_, (GtkWidget*) _tmp12_);
#line 63 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (_tmp12_);
#line 64 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp13_ = self->priv->italic_button;
#line 64 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp14_ = _ ("Italic");
#line 64 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_widget_set_tooltip_text ((GtkWidget*) _tmp13_, _tmp14_);
#line 65 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp15_ = self->priv->box;
#line 65 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp16_ = self->priv->italic_button;
#line 65 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_box_pack_start (_tmp15_, (GtkWidget*) _tmp16_, TRUE, FALSE, (guint) 0);
#line 67 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp17_ = (GtkToggleButton*) gtk_toggle_button_new ();
#line 67 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp17_);
#line 67 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->underline_button);
#line 67 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self->priv->underline_button = _tmp17_;
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp18_ = self->priv->underline_button;
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp19_ = (GtkImage*) gtk_image_new_from_icon_name ("format-text-underline-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp19_);
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp20_ = _tmp19_;
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_button_set_image ((GtkButton*) _tmp18_, (GtkWidget*) _tmp20_);
#line 68 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (_tmp20_);
#line 69 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp21_ = self->priv->underline_button;
#line 69 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp22_ = _ ("Underline");
#line 69 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_widget_set_tooltip_text ((GtkWidget*) _tmp21_, _tmp22_);
#line 70 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp23_ = self->priv->box;
#line 70 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp24_ = self->priv->underline_button;
#line 70 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_box_pack_start (_tmp23_, (GtkWidget*) _tmp24_, TRUE, FALSE, (guint) 0);
#line 72 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp25_ = (GtkToggleButton*) gtk_toggle_button_new ();
#line 72 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp25_);
#line 72 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->strikethrough_button);
#line 72 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self->priv->strikethrough_button = _tmp25_;
#line 73 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp26_ = self->priv->strikethrough_button;
#line 73 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp27_ = (GtkImage*) gtk_image_new_from_icon_name ("format-text-strikethrough-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);
#line 73 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_object_ref_sink (_tmp27_);
#line 73 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp28_ = _tmp27_;
#line 73 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_button_set_image ((GtkButton*) _tmp26_, (GtkWidget*) _tmp28_);
#line 73 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (_tmp28_);
#line 74 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp29_ = self->priv->strikethrough_button;
#line 74 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp30_ = _ ("Strikethrough");
#line 74 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_widget_set_tooltip_text ((GtkWidget*) _tmp29_, _tmp30_);
#line 75 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp31_ = self->priv->box;
#line 75 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp32_ = self->priv->strikethrough_button;
#line 75 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_box_pack_start (_tmp31_, (GtkWidget*) _tmp32_, TRUE, FALSE, (guint) 0);
#line 77 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp33_ = self->priv->box;
#line 77 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp33_);
#line 294 "FormatPopover.c"
}


static void __lambda8_ (KeepWidgetsFormatPopover* self) {
#line 81 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_emit_by_name (self, "bold-button-pressed");
#line 301 "FormatPopover.c"
}


static void ___lambda8__gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 81 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	__lambda8_ ((KeepWidgetsFormatPopover*) self);
#line 308 "FormatPopover.c"
}


static void __lambda9_ (KeepWidgetsFormatPopover* self) {
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_emit_by_name (self, "italic-button-pressed");
#line 315 "FormatPopover.c"
}


static void ___lambda9__gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	__lambda9_ ((KeepWidgetsFormatPopover*) self);
#line 322 "FormatPopover.c"
}


static void __lambda10_ (KeepWidgetsFormatPopover* self) {
#line 83 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_emit_by_name (self, "underline-button-pressed");
#line 329 "FormatPopover.c"
}


static void ___lambda10__gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 83 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	__lambda10_ ((KeepWidgetsFormatPopover*) self);
#line 336 "FormatPopover.c"
}


static void __lambda11_ (KeepWidgetsFormatPopover* self) {
#line 84 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_emit_by_name (self, "strikethrough-button-pressed");
#line 343 "FormatPopover.c"
}


static void ___lambda11__gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 84 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	__lambda11_ ((KeepWidgetsFormatPopover*) self);
#line 350 "FormatPopover.c"
}


static void keep_widgets_format_popover_connect_signals (KeepWidgetsFormatPopover* self) {
	GtkToggleButton* _tmp0_ = NULL;
	GtkToggleButton* _tmp1_ = NULL;
	GtkToggleButton* _tmp2_ = NULL;
	GtkToggleButton* _tmp3_ = NULL;
#line 80 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_return_if_fail (self != NULL);
#line 81 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp0_ = self->priv->bold_button;
#line 81 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_connect_object ((GtkButton*) _tmp0_, "clicked", (GCallback) ___lambda8__gtk_button_clicked, self, 0);
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp1_ = self->priv->italic_button;
#line 82 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_connect_object ((GtkButton*) _tmp1_, "clicked", (GCallback) ___lambda9__gtk_button_clicked, self, 0);
#line 83 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp2_ = self->priv->underline_button;
#line 83 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_connect_object ((GtkButton*) _tmp2_, "clicked", (GCallback) ___lambda10__gtk_button_clicked, self, 0);
#line 84 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_tmp3_ = self->priv->strikethrough_button;
#line 84 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_connect_object ((GtkButton*) _tmp3_, "clicked", (GCallback) ___lambda11__gtk_button_clicked, self, 0);
#line 377 "FormatPopover.c"
}


static void keep_widgets_format_popover_class_init (KeepWidgetsFormatPopoverClass * klass) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	keep_widgets_format_popover_parent_class = g_type_class_peek_parent (klass);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_type_class_add_private (klass, sizeof (KeepWidgetsFormatPopoverPrivate));
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	G_OBJECT_CLASS (klass)->finalize = keep_widgets_format_popover_finalize;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_new ("bold_button_pressed", KEEP_WIDGETS_TYPE_FORMAT_POPOVER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_new ("italic_button_pressed", KEEP_WIDGETS_TYPE_FORMAT_POPOVER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_new ("underline_button_pressed", KEEP_WIDGETS_TYPE_FORMAT_POPOVER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	g_signal_new ("strikethrough_button_pressed", KEEP_WIDGETS_TYPE_FORMAT_POPOVER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
#line 396 "FormatPopover.c"
}


static void keep_widgets_format_popover_instance_init (KeepWidgetsFormatPopover * self) {
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self->priv = KEEP_WIDGETS_FORMAT_POPOVER_GET_PRIVATE (self);
#line 403 "FormatPopover.c"
}


static void keep_widgets_format_popover_finalize (GObject* obj) {
	KeepWidgetsFormatPopover * self;
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, KEEP_WIDGETS_TYPE_FORMAT_POPOVER, KeepWidgetsFormatPopover);
#line 25 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->box);
#line 28 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->bold_button);
#line 29 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->italic_button);
#line 30 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->underline_button);
#line 31 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	_g_object_unref0 (self->priv->strikethrough_button);
#line 23 "/home/samthomas/Development/Vala/Keep/src/Widgets/FormatPopover.vala"
	G_OBJECT_CLASS (keep_widgets_format_popover_parent_class)->finalize (obj);
#line 423 "FormatPopover.c"
}


GType keep_widgets_format_popover_get_type (void) {
	static volatile gsize keep_widgets_format_popover_type_id__volatile = 0;
	if (g_once_init_enter (&keep_widgets_format_popover_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (KeepWidgetsFormatPopoverClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) keep_widgets_format_popover_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (KeepWidgetsFormatPopover), 0, (GInstanceInitFunc) keep_widgets_format_popover_instance_init, NULL };
		GType keep_widgets_format_popover_type_id;
		keep_widgets_format_popover_type_id = g_type_register_static (gtk_popover_get_type (), "KeepWidgetsFormatPopover", &g_define_type_info, 0);
		g_once_init_leave (&keep_widgets_format_popover_type_id__volatile, keep_widgets_format_popover_type_id);
	}
	return keep_widgets_format_popover_type_id__volatile;
}



