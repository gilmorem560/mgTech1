/*
 * logo - display a simple logo screen
 */ 
#ifndef __LOGO_H__
#define __LOGO_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "modes.h"
extern mode m_logo;

#define LOGO_SCENE_STUDIO	0
#define LOGO_SCENE_DEV		1
#define LOGO_SCENE_INIT		LOGO_SCENE_STUDIO
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __LOGO_H__ */
