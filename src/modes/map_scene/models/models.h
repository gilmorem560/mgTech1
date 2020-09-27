/*
 * models - models defined for map
 */ 
#ifndef __MODELS_H__
#define __MODELS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "../../../scene/model.h"
	
#define MT_TRIANGLE	0
extern void mt_map_triangle_new(model *this);
#define MT_CAMERA	1
#define MT_LOGO		2
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __MODELS_H__ */
