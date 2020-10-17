/*
 * map - a single game map
 */
#include "map.h"
#include "map_scene/nodes/nodes.h"
#include "../scene/scene.h"
#include "../graphics/graphics.h"
#include "../sound/sound.h"
#include "../input/input.h"

static scene *graph;
static unsigned int i;

static void map_init(void);
static void map_free(void);
static void map_input(void);
static void map_routine(void);
static void map_nextscene(void);

/* m_map - default map for testing, selection will be made by calling mode */
mode m_map = { M_MAP_T, MAP_SCENE_INIT, &map_init, &map_free, &map_routine, &map_nextscene };

/* init - setup graphics and memory objects */
void map_init(void)
{
	node *current_node;
	point3f pos = { 0.0f, 0.0f, -2.0f };
	
	/* prepare graphics context */
	gfx_context.clearblack();	/* black background */
	gfx_context.setprj(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
	
	/* allocate memory for scene objects */
	graph = scene_init();
	
	/* prepare a triangle */
	current_node = node_new(NT_TRIANGLE, MT_TRIANGLE);
	current_node->position = pos;
	scene_addnode(graph, current_node);
	
	for (i = 0; i < graph->node_count; i++) {
		current_node = graph->node_tree[i];
		switch (current_node->type) {
			case NT_TRIANGLE:
				nt_map_triangle_new(current_node);
				break;
			default:
				break;
		}
		current_node->init(current_node);
	}
	
	return;
}

/* free - cleanup memory objects */
void map_free(void)
{
	for (i = 0; i < graph->node_count; i++)
		graph->node_tree[i]->free(graph->node_tree[i]);

	scene_free(graph);
	
	return;
}

/* input - input subroutine */
void map_input(void)
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
void map_routine(void)
{
	/* process mode-wide input */
	map_input();
	
	/* process scene action */
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
void map_nextscene(void)
{
	return;
}
