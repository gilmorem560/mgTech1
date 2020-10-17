/*
 * models - models defined for logo
 */ 
#ifndef __MODELS_H__
#define __MODELS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "../../../scene/model.h"
	
#define MT_TRIANGLE	0
extern void mt_logo_triangle_new(model *this);
#define MT_TET		1
extern void mt_logo_tet_new(model *this);
#define MT_CAMERA	2
#define MT_LOGO		3
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __MODELS_H__ */
