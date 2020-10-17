/*
 * modes - game modes
 */ 
#ifndef __MODES_H__
#define __MODES_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
typedef struct mode {
	int type;
	int scene_index;
	void (*init)(void);
	void (*free)(void);
	void (*routine)(void);
	void (*nextscene)(void);
} mode;
	
#include "logo.h"
#define M_LOGO_T	0
#include "map.h"
#define M_MAP_T		1

#define init_mode	m_map
#define INIT_MODE 	M_MAP_T
#define INIT_SCENE	MAP_SCENE_INIT
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __MODES_H__ */
