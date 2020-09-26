/*
 * glxcontext - OpenGL X11 context
 */
#ifndef __GLXCONTEXT_H__
#define __GLXCONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "glcontext.h"
typedef glcontext glxcontext;

#include <X11/Xlib.h>   	/* X11 libraries */
#include <X11/cursorfont.h>	/* X11 cursor fonts */

#ifdef  HAVE_GL_GLX_H   	/* OpenGL X11 extensions */
#include <GL/glx.h>
#elif defined(HAVE_OPENGL_GLX_H)
#include <OpenGL/glx.h>
#endif /* HAVE_GL_GLX_H, HAVE_OPENGL_GLX_H */

extern const glxcontext gfx_context;
extern Display *dpy;	/* extern for input */
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __GLXCONTEXT_H__ */ 
