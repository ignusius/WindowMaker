/*
 *  Window Maker window manager
 *
 *  Copyright (c) 1997-2003 Alfredo K. Kojima
 *  Copyright (c) 2013 Window Maker Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef WMMISC_H_
#define WMMISC_H_

#include "appicon.h"


Bool wFetchName(Display *dpy, Window win, char **winname);
Bool wGetIconName(Display *dpy, Window win, char **iconname);
Bool UpdateDomainFile(WDDomain * domain);

void move_window(Window win, int from_x, int from_y, int to_x, int to_y);
void SlideWindow(Window win, int from_x, int from_y, int to_x, int to_y);
void SlideWindows(Window *wins[], int n, int from_x, int from_y, int to_x, int to_y);
void ParseWindowName(WMPropList * value, char **winstance, char **wclass, char *where);
void SendHelperMessage(WScreen * scr, char type, int workspace, char *msg);

char *ShrinkString(WMFont * font, char *string, int width);
char *FindImage(char *paths, char *file);
char *ExpandOptions(WScreen * scr, char *cmdline);
char *GetShortcutString(char *text);
char *GetShortcutKey(WShortKey key);
char *EscapeWM_CLASS(char *name, char *class);
char *StrConcatDot(char *a, char *b);
char *GetCommandForWindow(Window win);
#endif