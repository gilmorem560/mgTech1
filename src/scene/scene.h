/*
 * scene - a scene graph
 */
#ifndef __SCENE_H__
#define __SCENE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "node.h"

/*
 * scene - a scene graph
 */
typedef struct scene {
	node **node_tree;			/* the collection of nodes */
	unsigned int node_count;	/* count of above */
	node *camera;				/* the camera node */
} scene;


/* init - prepare resources */
extern scene *scene_init(void);
/* addnode - add a node to the tree, return position in root collection, NODE_ID_NULL on error */
extern unsigned int scene_addnode(scene *this, node *new_node);
/* addchildnode - add a node as a child of node.id == parent_id, return position in parent's collection, NODE_ID_NULL on error */
extern unsigned int scene_addchildnode(scene *this, node *child_node, unsigned int parent_id);
/* deletenode - carefully remove a node and clean the collections */
extern void scene_deletenode(scene *this, unsigned int node_id);
/* free - free all resources */
extern void scene_free(scene *this);
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __SCENE_H__ */
