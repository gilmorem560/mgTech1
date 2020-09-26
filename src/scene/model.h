/*
 * model - a model representing a node
 */
#ifndef __MODEL_H__
#define __MODEL_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "../common.h"
	
typedef struct model {
	unsigned int type;
	void (*render)(void);
	void (*routine)(void);
} model;

#define MT_DEFAULT	0

extern model *model_new(unsigned int type);
extern void model_free(model *this);

#include "node.h"
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __MODEL_H__ */
