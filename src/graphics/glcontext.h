/*
 * glcontext - OpenGL context 
 */
#ifndef __GLCONTEXT_H__
#define __GLCONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "graphics.h"
typedef gfxcontext glcontext;

#ifdef  HAVE_GL_GL_H    	/* OpenGL libraries */
#include <GL/gl.h>
#elif defined(HAVE_OPENGL_GL_H)
#include <OpenGL/gl.h>
#endif /* HAVE_GL_GL_H, HAVE_OPENGL_GL_H */
	
#if GFX_BACKEND == GFX_GLX
#include "glxcontext.h"
#elif GFX_BACKEND == GFX_WGL
#include "wglcontext.h"
#endif /* GFX_BACKEND */

extern void gl_clearblack(void);
extern void gl_clearscreen(void);
extern void gl_position(float x, float y, float z);
extern void gl_setprj(double left, double right, double bottom, double top, double nearVal, double farVal);
extern void gl_setortho(double left, double right, double bottom, double top, double nearVal, double farVal);
extern void gl_modelinit(void);
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __GLCONTEXT_H__ */ 
