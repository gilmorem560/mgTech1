/*
 * x11input - input support via X11
 */
#ifndef __X11INPUT_H__
#define __X11INPUT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "input.h"
typedef inputcontext x11inputcontext;

#include <X11/Xlib.h>   	/* X11 libraries */
#include <X11/XKBlib.h>		/* X11 Xkb extensions */

extern const x11inputcontext input_context;
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __X11INPUT_H__ */ 
