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
extern void nt_logo_triangle_new(node *this);
#define NT_TET		1
extern void nt_logo_tet_new(node *this);
#define NT_CAMERA	2
#define NT_LOGO		3
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __NODES_H__ */
