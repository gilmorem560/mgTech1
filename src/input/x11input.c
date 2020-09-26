/*
 * x11input - input support via X11
 */
#include <stdio.h>
#include "x11input.h"

/* x11 input coupled to x11 form */
#include "../graphics/glxcontext.h"

void x11input_init(void);
void x11input_free(void);
void x11input_poll(void);

const x11inputcontext input_context = { &x11input_init, &x11input_free, &x11input_poll };

/* x11input_init - initialize keyboard settings */
void x11input_init(void)
{
	/* allow auto-repeat of keys */
    XkbSetDetectableAutoRepeat(dpy, True, NULL);
	
	return;
}

/* x11input_free - null function as all free handled by window destruction */
void x11input_free(void)
{
	return;
}

/* x11input_poll - polls for x11 input events */
void x11input_poll(void)
{
	XEvent event_return;
	
	i_keypress = 0;
	
	while (XEventsQueued(dpy, QueuedAfterFlush) != 0) {
		XNextEvent(dpy, &event_return);
		switch (event_return.type) {
		case KeyPress:
			switch (XLookupKeysym(&event_return.xkey, 0)) {
				case XK_A:
				case XK_a:
					i_keypress = KEY_A;
					break;
				case XK_B:
				case XK_b:
					break;
				case XK_C:
				case XK_c:
					break;
				case XK_D:
				case XK_d:
					i_keypress = KEY_D;
					break;
				case XK_E:
				case XK_e:
					break;
				case XK_F:
				case XK_f:
					break;
				case XK_G:
				case XK_g:
					break;
				case XK_H:
				case XK_h:
					break;
				case XK_I:
				case XK_i:
					break;
				case XK_J:
				case XK_j:
					break;
				case XK_K:
				case XK_k:
					break;
				case XK_L:
				case XK_l:
					break;
				case XK_M:
				case XK_m:
					break;
				case XK_N:
				case XK_n:
					break;
				case XK_O:
				case XK_o:
					break;
				case XK_P:
				case XK_p:
					break;
				case XK_Q:
				case XK_q:
					i_keypress = KEY_Q;
					break;
				case XK_R:
				case XK_r:
					break;
				case XK_S:
				case XK_s:
					i_keypress = KEY_S;
					break;
				case XK_T:
				case XK_t:
					break;
				case XK_U:
				case XK_u:
					break;
				case XK_V:
				case XK_v:
					break;
				case XK_W:
				case XK_w:
					i_keypress = KEY_W;
					break;
				case XK_X:
				case XK_x:
					break;
				case XK_Y:
				case XK_y:
					break;
				case XK_Z:
				case XK_z:
					break;
				default:
					break;
			}
			i_keyheld |= i_keypress;
			break;
		case KeyRelease:
			switch (XLookupKeysym(&event_return.xkey, 0)) {
				case XK_A:
				case XK_a:
					i_keyheld &= ~KEY_A;
					break;
				case XK_B:
				case XK_b:
					break;
				case XK_C:
				case XK_c:
					break;
				case XK_D:
				case XK_d:
					i_keyheld &= ~KEY_D;
					break;
				case XK_E:
				case XK_e:
					break;
				case XK_F:
				case XK_f:
					break;
				case XK_G:
				case XK_g:
					break;
				case XK_H:
				case XK_h:
					break;
				case XK_I:
				case XK_i:
					break;
				case XK_J:
				case XK_j:
					break;
				case XK_K:
				case XK_k:
					break;
				case XK_L:
				case XK_l:
					break;
				case XK_M:
				case XK_m:
					break;
				case XK_N:
				case XK_n:
					break;
				case XK_O:
				case XK_o:
					break;
				case XK_P:
				case XK_p:
					break;
				case XK_Q:
				case XK_q:
					i_keyheld &= ~KEY_Q;
					break;
				case XK_R:
				case XK_r:
					break;
				case XK_S:
				case XK_s:
					i_keyheld &= ~KEY_S;
					break;
				case XK_T:
				case XK_t:
					break;
				case XK_U:
				case XK_u:
					break;
				case XK_V:
				case XK_v:
					break;
				case XK_W:
				case XK_w:
					i_keyheld &= ~KEY_W;
					break;
				case XK_X:
				case XK_x:
					break;
				case XK_Y:
				case XK_y:
					break;
				case XK_Z:
				case XK_z:
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
	}
}
