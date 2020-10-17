/*
 * scene - a scene graph
 */
#include "scene.h"

scene *scene_init(void)
{
	scene *this = malloc(sizeof (scene));
		this->node_tree = malloc(sizeof (node *));
		this->node_count = 0;
		this->camera = NULL;
		
	return this;
}

unsigned int scene_addnode(scene *this, node *new_node)
{
	unsigned int node_id = NODE_ID_NULL;
	
	if (new_node->id == NODE_ID_NULL) {
		this->node_tree = realloc(this->node_tree, ++this->node_count * sizeof (node *));
		node_id = this->node_count - 1;
		
		this->node_tree[node_id] = new_node;
		new_node->id = node_id;
	}
	
	return node_id;
}

unsigned int scene_addchildnode(scene *this, node *child_node, unsigned int parent_id)
{
	unsigned int child_id = NODE_ID_NULL;
	node *parent_node;
	
	if (child_node->parent_id == NODE_ID_NULL) {
		child_id = scene_addnode(this, child_node);
		if (child_id != NODE_ID_NULL) {
			parent_node = this->node_tree[parent_id];
			if (parent_node != NULL) {
				child_id = node_addchild(parent_node, child_node);
				child_node->parent_id = parent_id;
			} else
				child_id = NODE_ID_NULL;
		}
	}
		
	return child_id;
}

static void scene_prunenode(scene *this, unsigned int node_id)
{
	node **this_node = &this->node_tree[node_id];
	if (*this_node != NULL) {
		node_free(*this_node);
		*this_node = NULL;
	}
	return;
}

void scene_deletenode(scene *this, unsigned int node_id)
{
	node *this_node = this->node_tree[node_id];
	unsigned int parent_id = this_node->parent_id;
	unsigned int i;
	node *parent_node;
	node *child_node;
	
	for (i = 0; i < this_node->child_count; i++) {
		child_node = this_node->children[i];
		node_deletechild(this_node, child_node);
		child_node->parent_id = parent_id;
	}
	
	if (parent_id != NODE_ID_NULL) {
		parent_node = this->node_tree[parent_id];
		if (parent_node != NULL)
			node_orphanchild(parent_node, this_node);
	}
	
	/* prune from tree */
	scene_prunenode(this, node_id);
}

void scene_free(scene *this)
{
	unsigned int i;
	
	if (this->node_tree != NULL) {
		for (i = 0; i < this->node_count; i++)
			scene_prunenode(this, i);
		
		free(this->node_tree);
	}
	
	free(this);
	
	return;
}
