/*
 * map - a single game map
 */ 
#ifndef __MAP_H__
#define __MAP_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "modes.h"
extern mode m_map;

#define MAP_SCENE_LEVEL00	0
#define MAP_SCENE_LEVEL01	1
#define MAP_SCENE_INIT		MAP_SCENE_LEVEL00
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __MAP_H__ */
