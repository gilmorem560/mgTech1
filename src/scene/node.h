/*
 * node - a node in a scene graph
 */
#ifndef __NODE_H__
#define __NODE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "model.h"

typedef struct node {
	unsigned int id;
	model *geom;
	unsigned int type;
	unsigned int *children;
	unsigned int child_count;
	unsigned int parent_id;
	bool isactive;
	bool isrender;
	void (*init)(struct node *);
	void (*routine)(struct node *);
	void (*render)(struct node *);
	void (*free)(struct node *);
	point3f position;
	ang3f angle;
} node;

extern node *node_new(unsigned int type);
extern void node_setchild(node *this, node *child);
extern void node_orphanchild(node *this, node *child);
extern void node_deletechild(node *this, node *child);
extern void node_free(node *this);

#include "scene.h"
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __NODE_H__ */
