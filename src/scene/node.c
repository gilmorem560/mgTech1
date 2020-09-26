/*
 * node - a node in a scene graph
 */
#include "node.h"

node *node_new(unsigned int type)
{
	node *this = malloc(sizeof (node));
		this->geom = model_new(MT_DEFAULT);
		this->type = type;
		this->children = malloc(sizeof (int));
		this->child_count = 0;
		this->parent_id = 0;
		this->init = NULL;
		this->routine = NULL;
		this->render = NULL;
		this->free = NULL;
		this->properties = NULL;
	
	return this;
}

void node_setchild(node *this, node *child)
{
	int child_pos;
	
	/* add an entry in the child collection */
	this->children = realloc(this->children, ++this->child_count * sizeof (int));
	child_pos = this->child_count - 1;
	
	this->children[child_pos] = child->id;
	child->parent_id = this->id;
	
	return;
}

void node_orphanchild(node *this, node *child)
{
	int i;
	int child_count = 0;
	unsigned int *newset = malloc(sizeof (int) * (this->child_count - 1));
	
	for (i = 0; i < this->child_count; i++)
		if (this->children[i] != child->id)
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
	int i;
	model_free(this->geom);
	free(this->children);
	free(this);
	
	return;
}
