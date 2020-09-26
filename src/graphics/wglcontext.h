/*
 * wglcontext - OpenGL Windows context
 */
#ifndef __WGLCONTEXT_H__
#define __WGLCONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "glcontext.h"
typedef glcontext wglcontext;

extern wglcontext gfx_context;
extern void wgl_init(void);
extern void wgl_free(void);
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __WGLCONTEXT_H__ */ 
