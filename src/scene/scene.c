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

unsigned int scene_addnode(scene *this, unsigned int node_type)
{
	int node_id;
	
	this->node_tree = realloc(this->node_tree, ++this->node_count * sizeof (node *));
	node_id = this->node_count - 1;
	
	this->node_tree[node_id] = node_new(node_type);
		this->node_tree[node_id]->id = node_id;
	
	return node_id;
}

unsigned int scene_addchildnode(scene *this, unsigned int parent_id, unsigned int node_type)
{
	int child_id = scene_addnode(this, node_type);
	node *parent = this->node_tree[parent_id];
	
	if (parent != NULL)
		node_setchild(parent, this->node_tree[child_id]);
	
	return child_id;
}

static void scene_prunenode(scene *this, unsigned int node_id)
{
	if (this->node_tree[node_id] != NULL)
		node_free(this->node_tree[node_id]);
	return;
}

void scene_deletenode(scene *this, unsigned int node_id)
{
	int i;
	int child_id;
	node *this_node = this->node_tree[node_id];
	node *parent_node;
	
	/* orphan the node */
	if (this_node->parent_id != 0) {
		parent_node = this->node_tree[this_node->parent_id];
		node_orphanchild(parent_node, this_node);
	}
	
	/* orphan the children */
	for (i = 0; i < this_node->child_count; i++) {
		child_id = this_node->children[i];
		node_orphanchild(this_node, this->node_tree[child_id]);
	}
	
	/* prune from tree */
	scene_prunenode(this, node_id);
}

void scene_free(scene *this)
{
	int i;
	
	if (this->node_tree != NULL) {
		for (i = 0; i < this->node_count; i++) {
			scene_prunenode(this, i);
		}
		
		free(this->node_tree);
	}
	
	free(this);
	
	return;
}
