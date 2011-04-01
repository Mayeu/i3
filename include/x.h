/*
 * vim:ts=4:sw=4:expandtab
 */

#ifndef _X_H
#define _X_H

/** Stores the X11 window ID of the currently focused window */
extern xcb_window_t focused_id;

/**
 * Initializes the X11 part for the given container. Called exactly once for
 * every container from con_new().
 *
 */
void x_con_init(Con *con);

/**
 * Moves a child window from Container src to Container dest.
 *
 */
void x_move_win(Con *src, Con *dest);

/**
 * Reparents the child window of the given container (necessary for sticky
 * containers). The reparenting happens in the next call of x_push_changes().
 *
 */
void x_reparent_child(Con *con, Con *old);

/**
 * Re-initializes the associated X window state for this container. You have
 * to call this when you assign a client to an empty container to ensure that
 * its state gets updated correctly.
 *
 */
void x_reinit(Con *con);

/**
 * Kills the window decoration associated with the given container.
 *
 */
void x_con_kill(Con *con);

/**
 * Returns true if the client supports the given protocol atom (like WM_DELETE_WINDOW)
 *
 */
bool window_supports_protocol(xcb_window_t window, xcb_atom_t atom);

/**
 * Kills the given X11 window using WM_DELETE_WINDOW (if supported).
 *
 */
void x_window_kill(xcb_window_t window);

/**
 * Draws the decoration of the given container onto its parent.
 *
 */
void x_draw_decoration(Con *con);

/**
 * This function pushes the properties of each node of the layout tree to
 * X11 if they have changed (like the map state, position of the window, …).
 * It recursively traverses all children of the given node.
 *
 */
void x_push_node(Con *con, bool skip_decoration);

/**
 * Pushes all changes (state of each node, see x_push_node() and the window
 * stack) to X11.
 *
 */
void x_push_changes(Con *con);

/**
 * Raises the specified container in the internal stack of X windows. The
 * next call to x_push_changes() will make the change visible in X11.
 *
 */
void x_raise_con(Con *con);

/**
 * Sets the WM_NAME property (so, no UTF8, but used only for debugging anyways)
 * of the given name. Used for properly tagging the windows for easily spotting
 * i3 windows in xwininfo -root -all.
 *
 */
void x_set_name(Con *con, const char *name);

/**
 * Sets up i3 specific atoms (I3_SOCKET_PATH and I3_CONFIG_PATH)
 *
 */
void x_set_i3_atoms();

#endif
