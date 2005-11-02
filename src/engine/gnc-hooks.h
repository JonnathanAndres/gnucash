/*
 * gnc-hooks.h -- helpers for using Glib hook functions
 * Copyright (C) 2005 David Hampton <hampton@employees.org>
 *                    Derek Atkins <derek@ihtfp.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, contact:
 *
 * Free Software Foundation           Voice:  +1-617-542-5942
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652
 * Boston, MA  02111-1307,  USA       gnu@gnu.org
 *
 */

#ifndef GNC_HOOKS_H
#define GNC_HOOKS_H

/**
 * Create a new hook.  Not a common occurrance, but...
 * The returned string is just the 'name' argument,
 * which belongs to the caller.
 */
gchar * gnc_hook_create(const gchar *name, gint num_args, const gchar *desc);

/**
 * lookup the description of a hook.  returned description belongs to
 * the hook and not the caller
 */
gchar * gnc_hook_get_description(const gchar *name);

/**
 * add and remove C-style dangers from a hook.  The callback is called
 *   function(hook_run_data, cb_data)
 */
void gnc_hook_add_dangler(const gchar *name, GFunc callback, gpointer cb_data);
void gnc_hook_remove_dangler(const gchar *name, GFunc callback);

/**
 * Run the hook danglers.
 */
void gnc_hook_run(const gchar *name, gpointer data);

/**
 * Initialize the known hooks
 */
void gnc_hooks_init(void);

/* Common hook names */
#define HOOK_STARTUP		"hook_startup"
#define HOOK_SHUTDOWN		"hook_shutdown"
#define HOOK_UI_STARTUP		"hook_ui_startup"
#define HOOK_UI_POST_STARTUP	"hook_ui_post_startup"
#define HOOK_UI_SHUTDOWN	"hook_ui_shutdown"
#define HOOK_NEW_BOOK		"hook_new_book"
#define HOOK_REPORT		"hook_report"
#define HOOK_SAVE_OPTIONS	"hook_save_options"
#define HOOK_ADD_EXTENSION	"hook_add_extension"

/* Common session hook names */
#define HOOK_BOOK_OPENED	"hook_book_opened"
#define HOOK_BOOK_CLOSED	"hook_book_closed"

#endif /* GNC_HOOKS_H */
