/*
 * logo - display a simple logo screen
 */
#include "logo.h"
#include "logo_scene/nodes/nodes.h"
#include "../scene/scene.h"
#include "../graphics/graphics.h"
#include "../sound/sound.h"
#include "../input/input.h"

static scene *graph;
static unsigned int i;

static void logo_init(void);
static void logo_free(void);
static void logo_input(void);
static void logo_routine(void);
static void logo_nextscene(void);

/* m_logo - default logo screen, create unique "scenes" with a logo texture'd node with a timer */
mode m_logo = { M_LOGO_T, LOGO_SCENE_INIT, &logo_init, &logo_free, &logo_routine, &logo_nextscene };

/* init - setup graphics and memory objects */
void logo_init(void)
{
	node *current_node;
	node *tet;
	unsigned int current_node_id;
	point3f tet_pos = { 0.5f, 0.5f, -2.0f };
	
	/* prepare graphics context */
	gfx_context.clearblack();	/* black background */
	gfx_context.setprj(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
	gfx_context.setprops(GFX_DEPTH_BUFFER | GFX_CULLING);
	
	/* allocate memory for scene objects */
	graph = scene_init();
	
	/* prepare a tetrahedron */
	tet = node_new(NT_TRIANGLE, MT_TET);
	tet->position = tet_pos;
	scene_addnode(graph, tet);
	
	for (i = 0; i < graph->node_count; i++) {
		current_node = graph->node_tree[i];
		switch (current_node->type) {
			case NT_TRIANGLE:
				nt_logo_triangle_new(current_node);
				break;
			case NT_TET:
				nt_logo_tet_new(current_node);
				break;
			default:
				break;
		}
		current_node->init(current_node);
	}
	
	return;
}

/* free - cleanup memory objects */
void logo_free(void)
{
	for (i = 0; i < graph->node_count; i++)
		graph->node_tree[i]->free(graph->node_tree[i]);

	scene_free(graph);
	
	return;
}

/* input - input subroutine */
void logo_input(void)
{
	if (i_keypress & KEY_Q)
		f_running = false;
	
	return;
}

/* routine - perform various mode activities such as:
 * 	processing input
 * 	performing transformations
 * 	assessing and applying constraints & collision
 * 	preparing display lists and loading VBOs
 */
void logo_routine(void)
{
	logo_input();
	
	for (i = 0; i < graph->node_count; i++)
		if (graph->node_tree[i] != NULL && graph->node_tree[i]->isactive == true)
			graph->node_tree[i]->routine(graph->node_tree[i]);
		
	gfx_context.clearscreen();	
	gfx_context.model_init();

	/* prepare scene graphics */
	for (i = 0; i < graph->node_count; i++)
		if (graph->node_tree[i] != NULL && graph->node_tree[i]->isrender == true)
			graph->node_tree[i]->render(graph->node_tree[i]);

	return;
}

/* nextscene - retain the current mode and load in another scene utilizing the same mode */
void logo_nextscene(void)
{
	return;
}
