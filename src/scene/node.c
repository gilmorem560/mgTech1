/*
 * node - a node in a scene graph
 */
#include "node.h"

node *node_new(unsigned int type, unsigned int model_type)
{
	vect3f init_val = { 0.0f, 0.0f, 0.0f };
	node *this = malloc(sizeof (node));
		this->id = NODE_ID_NULL;
		this->geom = model_new(model_type);
		this->type = type;
		this->children = malloc(sizeof (node *));
		this->child_count = 0;
		this->parent_id = NODE_ID_NULL;
		this->isactive = true;
		this->isrender = true;
		this->init = NULL;
		this->routine = NULL;
		this->render = NULL;
		this->free = NULL;
		this->position = init_val;
		this->angle = init_val;
		this->rot = 0.0f;
	
	return this;
}

unsigned int node_addchild(node *this, node *child)
{
	unsigned int child_pos;
	
	this->children = realloc(this->children, ++this->child_count * sizeof (node *));
	child_pos = this->child_count - 1;
	
	this->children[child_pos] = child;
	
	return child_pos;
}

void node_orphanchild(node *this, node *child)
{
	int i;
	unsigned int child_count = 0;
	node **newset = malloc(sizeof (node *) * (this->child_count - 1));
	
	for (i = 0; i < this->child_count; i++)
		if (this->children[i] != child)
			newset[child_count++] = this->children[i];

	free(this->children);
	
	this->children = newset;
	this->child_count = child_count;
	
	child->parent_id = 0;
	
	return;
}

void node_deletechild(node *this, node *child)
{
	node_orphanchild(this, child);
	node_free(child);
	
	return;
}

void node_free(node *this)
{
	model_free(this->geom);
	free(this->children);
	free(this);
	
	return;
}
