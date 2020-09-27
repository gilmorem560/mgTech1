/*
 * common - common includes and defines
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
/* standard includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "common/types.h"	/* useful types */

/* global symbols */
extern bool f_debug;		/* debug mode */
extern bool f_running;		/* running mode */

/* build parameters - lazy... */

/* graphics backend to bundle */
#define GFX_GLX	0 /* X11 OpenGL */
#define GFX_WGL 1 /* Windows OpenGL */
#define GFX_VKX 2 /* X11 Vulkan */
#define GFX_VKW 3 /* Windows Vulkan */
#define GFX_M   4 /* Apple Metal */
#define GFX_DX  5 /* Windows DirectX */

/* input backend to bundle */
#define INPUT_X11 0 /* X11 input */
#define INPUT_WIN 1 /* Windows input */

/* joypad extension */
#define JOYPAD_EVDEV 0 /* evdev joypads */
#define JOYPAD_WIN	 1 /* windows joypads */

/* sound backend */
#define SND_ALSA	0 /* ALSA for linux */
#define SND_WIN		1 /* Windows sound */

/* build system */
#define LINUX_GL	0
#define WINDOWS_GL	1
#define BUILD_SYSTEM LINUX_GL

#if BUILD_SYSTEM == LINUX_GL
#define GFX_BACKEND GFX_GLX
#define INPUT_BACKEND INPUT_X11
#define JOYPAD_BACKEND JOYPAD_EVDEV
#define SND_BACKEND SND_ALSA
#define HAS_COMMAND_ARGS 1
#define HAVE_GL_GL_H
#define HAVE_GL_GLX_H
#elif BUILD_SYSTEM == WINDOWS_GL
#define GFX_BACKEND GFX_WGL
#define INPUT_BACKEND INPUT_WIN
#define JOYPAD_BACKEND JOYPAD_WIN
#define SND_BACKEND SND_WIN
#define HAS_COMMAND_ARGS 1
#define HAVE_GL_GL_H
#endif /* BUILD_SYSTEM */

/* end build parameters */
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __COMMON_H__ */
