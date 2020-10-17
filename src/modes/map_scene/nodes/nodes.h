/*
 * nodes - nodes defined for map
 */ 
#ifndef __NODES_H__
#define __NODES_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "../../../scene/scene.h"
#include "../models/models.h"
	
#define NT_TRIANGLE	0
extern void nt_map_triangle_new(node *this);
#define NT_CAMERA	1
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __NODES_H__ */
