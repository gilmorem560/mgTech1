/*
 * graphics - graphics subsystem
 */
#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "../common.h"
	
enum gfx_props {
	GFX_DEPTH_BUFFER = 1
	,GFX_CULLING = 2
};
	
/* gfxcontext - contains the basic functions necessary to a game's rendering engine */
typedef struct gfxcontext {
	void (*init)(void);
	void (*free)(void);
	void (*draw)(void);
	void (*clearblack)(void);
	void (*clearscreen)(void);
	void (*startmatrix)(void);
	void (*stopmatrix)(void);
	void (*position)(float, float, float);
	void (*rotate)(float, float, float, float);
	void (*setprj)(double, double, double, double, double, double);
	void (*setortho)(double, double, double, double, double, double);
	void (*model_init)(void);
	void (*setprops)(enum gfx_props);
} gfxcontext;

#if GFX_BACKEND == GFX_GLX || GFX_BACKEND == GFX_WGL
#include "glcontext.h"
#endif /* GFX_BACKEND */

extern unsigned short g_xres;
extern unsigned short g_yres;
extern float g_aspect_ratio;
extern bool g_fullscreen;
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __GRAPHICS_H__ */
