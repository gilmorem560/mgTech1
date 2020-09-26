/*
 * scene - a scene graph
 */
#ifndef __SCENE_H__
#define __SCENE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "node.h"
	
typedef struct scene {
	node **node_tree;
	unsigned int node_count;
	node *camera;
} scene;

extern scene *scene_init(void);
/* addnode - create a node of the given type, add to base collection */
extern unsigned int scene_addnode(scene *this, unsigned int node_type);
/* addchildnode - create a node of the given type, add as child of given parent */
extern unsigned int scene_addchildnode(scene *this, unsigned int parent_id, unsigned int node_type);
/* deletenode - carefully remove a node and clean the collections */
extern void scene_deletenode(scene *this, unsigned int node_id);
/* free - free all resources */
extern void scene_free(scene *this);
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __SCENE_H__ */
