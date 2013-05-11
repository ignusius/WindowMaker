/*
 *  Window Maker window manager
 *
 *  Copyright (c) 1997-2003 Alfredo K. Kojima
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

#ifndef WMFUNCS_H_
#define WMFUNCS_H_

#include <sys/types.h>
#include <stdio.h>

#include "window.h"
#include "defaults.h"
#include "keybind.h"

typedef void (WCallBack)(void *cdata);
typedef void (WDeathHandler)(pid_t pid, unsigned int status, void *cdata);

void DispatchEvent(XEvent *event);
void UpdateSwitchMenu(WScreen *scr, WWindow *wwin, int action);
void OpenSwitchMenu(WScreen *scr, int x, int y, int keyboard);
void InitializeSwitchMenu(void);
void OpenWindowMenu(WWindow *wwin, int x, int y, int keyboard);
void OpenWindowMenu2(WWindow *wwin, int x, int y, int keyboard);
void OpenMiniwindowMenu(WWindow *wwin, int x, int y);
void CloseWindowMenu(WScreen *scr);
void DestroyWindowMenu(WScreen *scr);
void StartWindozeCycle(WWindow *wwin, XEvent *event, Bool next, Bool class_only);

void wHackedGrabButton(unsigned int button, unsigned int modifiers,
                       Window grab_window, Bool owner_events,
                       unsigned int event_mask, int pointer_mode,
                       int keyboard_mode, Window confine_to, Cursor cursor);

WMagicNumber wAddDeathHandler(pid_t pid, WDeathHandler *callback, void *cdata);

Bool IsDoubleClick(WScreen *scr, XEvent *event);

#ifdef NUMLOCK_HACK
void wHackedGrabKey(int keycode, unsigned int modifiers,
                    Window grab_window, Bool owner_events, int pointer_mode,
                    int keyboard_mode);
#endif

Bool GetCommandForPid(int pid, char ***argv, int *argc);

int getWVisualID(int screen);
#endif
