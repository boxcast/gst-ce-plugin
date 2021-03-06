/*
 * gstceslicepool.h
 *
 * Copyright (C) 2013 RidgeRun, LLC (http://www.ridgerun.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses>.
 *
 */

#ifndef __GST_CE_SLICE_POOL_H__
#define __GST_CE_SLICE_POOL_H__

#include <gst/gst.h>

G_BEGIN_DECLS
/* slice bufferpool */
typedef struct _GstCeSliceBufferPool GstCeSliceBufferPool;
typedef struct _GstCeSliceBufferPoolClass GstCeSliceBufferPoolClass;
typedef struct _GstCeSliceBufferPoolPrivate GstCeSliceBufferPoolPrivate;

#define GST_TYPE_CE_SLICE_BUFFER_POOL      (gst_ce_slice_buffer_pool_get_type())
#define GST_IS_CE_SLICE_BUFFER_POOL(obj)   (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GST_TYPE_CE_SLICE_BUFFER_POOL))
#define GST_CE_SLICE_BUFFER_POOL(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GST_TYPE_CE_SLICE_BUFFER_POOL, GST_TYPE_CE_SLICE_BUFFER_POOL))
#define GST_CE_SLICE_BUFFER_POOL_CAST(obj) ((GstCeSliceBufferPool*)(obj))

struct _GstCeSliceBufferPool
{
  GstBufferPool bufferpool;

  GstCeSliceBufferPoolPrivate *priv;
};

struct _GstCeSliceBufferPoolClass
{
  GstBufferPoolClass parent_class;
};

GType gst_ce_slice_buffer_pool_get_type (void);
GstBufferPool *gst_ce_slice_buffer_pool_new (void);
gboolean gst_ce_slice_buffer_resize (GstCeSliceBufferPool * spool,
    GstBuffer * buffer, gint size);
gboolean gst_ce_slice_buffer_pool_set_min_size (GstCeSliceBufferPool * spool,
    guint size, gboolean is_percentange);
G_END_DECLS
#endif /*__GST_CE_SLICE_POOL_H__*/
