/*
 * joystick - joystick support
 */
#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "input.h"
	
#if JOYSTICK_BACKEND == JOYSTICK_EVDEV
#include "joystick_evdev.h"
#elif JOYSTICK_BACKEND == JOYSTICK_WIN
#include "joystick_win.h"
#endif /* JOYSTICK_BACKEND */
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __JOYSTICK_H__ */ 
