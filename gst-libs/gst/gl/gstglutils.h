/*
 * GStreamer
 * Copyright (C) 2013 Matthew Waters <ystreet00@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_GL_UTILS_H__
#define __GST_GL_UTILS_H__

#include <gst/video/video.h>
#include <gst/video/gstvideoaffinetransformationmeta.h>

#include <gst/gl/gstgl_fwd.h>

G_BEGIN_DECLS

/**
 * CDCB:
 * @texture: texture to draw
 * @width: new width
 * @height: new height:
 * @data: user data
 *
 * client draw callback
 */
typedef gboolean (*CDCB) (GLuint texture, GLuint width, GLuint height, gpointer data);
/**
 * GLCB:
 * @width: the width
 * @height: the height
 * @texture: texture
 * @stuff: user data
 *
 * callback definition for operating on textures
 */
typedef void (*GLCB) (gint, gint, guint, gpointer stuff);

gboolean gst_gl_context_gen_shader (GstGLContext * context,
    const gchar * shader_vertex_source,
    const gchar * shader_fragment_source, GstGLShader ** shader);
void gst_gl_context_del_shader (GstGLContext * context, GstGLShader * shader);

gboolean gst_gl_ensure_element_data (gpointer element,
    GstGLDisplay **display_ptr, GstGLContext ** other_context_ptr);
gboolean gst_gl_handle_set_context (GstElement * element, GstContext * context, 
    GstGLDisplay ** display, GstGLContext ** other_context);
gboolean gst_gl_handle_context_query (GstElement * element, GstQuery * query, 
    GstGLDisplay ** display, GstGLContext ** other_context);

gboolean gst_gl_run_query (GstElement * element,
    GstQuery * query, GstPadDirection direction);
gsize gst_gl_get_plane_data_size (GstVideoInfo * info, GstVideoAlignment * align,
    guint plane);
gsize gst_gl_get_plane_start (GstVideoInfo * info, GstVideoAlignment * valign,
    guint plane);
GstCaps * gst_gl_caps_replace_all_caps_features (const GstCaps * caps,
    const gchar * feature_name);

gboolean gst_gl_value_set_texture_target_from_mask (GValue * value,
    GstGLTextureTarget target_mask);
gboolean gst_gl_value_set_texture_target (GValue * value, GstGLTextureTarget target);
GstGLTextureTarget gst_gl_value_get_texture_target_mask (const GValue * value);

void gst_gl_multiply_matrix4 (const gfloat * a, const gfloat * b, gfloat * result);
void gst_gl_get_affine_transformation_meta_as_ndc (GstVideoAffineTransformationMeta *
    meta, gfloat * matrix);

G_END_DECLS

#endif /* __GST_GL_UTILS_H__ */
