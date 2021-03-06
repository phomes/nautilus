/*
   nautilus-desktop-file.h: Subclass of NautilusFile to implement the
   the case of a desktop icon file

   Copyright (C) 2003 Red Hat, Inc.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with this program; if not, see <http://www.gnu.org/licenses/>.

   Author: Alexander Larsson <alexl@redhat.com>
*/

#ifndef NAUTILUS_DESKTOP_ICON_FILE_H
#define NAUTILUS_DESKTOP_ICON_FILE_H

#include "nautilus-desktop-link.h"

#include <src/nautilus-file.h>

#define NAUTILUS_TYPE_DESKTOP_ICON_FILE nautilus_desktop_icon_file_get_type()
#define NAUTILUS_DESKTOP_ICON_FILE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), NAUTILUS_TYPE_DESKTOP_ICON_FILE, NautilusDesktopIconFile))
#define NAUTILUS_DESKTOP_ICON_FILE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), NAUTILUS_TYPE_DESKTOP_ICON_FILE, NautilusDesktopIconFileClass))
#define NAUTILUS_IS_DESKTOP_ICON_FILE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NAUTILUS_TYPE_DESKTOP_ICON_FILE))
#define NAUTILUS_IS_DESKTOP_ICON_FILE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), NAUTILUS_TYPE_DESKTOP_ICON_FILE))
#define NAUTILUS_DESKTOP_ICON_FILE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), NAUTILUS_TYPE_DESKTOP_ICON_FILE, NautilusDesktopIconFileClass))

typedef struct NautilusDesktopIconFileDetails NautilusDesktopIconFileDetails;

typedef struct {
	NautilusFile parent_slot;
	NautilusDesktopIconFileDetails *details;
} NautilusDesktopIconFile;

typedef struct {
	NautilusFileClass parent_slot;
} NautilusDesktopIconFileClass;

GType   nautilus_desktop_icon_file_get_type (void);

NautilusDesktopIconFile *nautilus_desktop_icon_file_new      (NautilusDesktopLink     *link);
void                     nautilus_desktop_icon_file_update   (NautilusDesktopIconFile *icon_file);
void                     nautilus_desktop_icon_file_remove   (NautilusDesktopIconFile *icon_file);
NautilusDesktopLink     *nautilus_desktop_icon_file_get_link (NautilusDesktopIconFile *icon_file);

#endif /* NAUTILUS_DESKTOP_ICON_FILE_H */
