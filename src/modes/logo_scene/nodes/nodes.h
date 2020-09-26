/*
 * nodes - nodes defined for logo
 */ 
#ifndef __NODES_H__
#define __NODES_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "../../../scene/scene.h"
#include "../models/models.h"
	
#define NT_TRIANGLE	0
extern void nt_triangle_new(node *this);
#define NT_CAMERA	1
#define NT_LOGO		2
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __NODES_H__ */
