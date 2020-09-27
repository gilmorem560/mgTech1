/*
 * logo - display a simple logo screen
 */
#include "logo.h"
#include "logo_scene/nodes/nodes.h"
#include "../scene/scene.h"
#include "../graphics/graphics.h"
/*#include "../sound/sound.h"*/
#include "../input/input.h"

scene *logo_scene;

void logo_init(void);
void logo_free(void);
void logo_input(void);
void logo_routine(void);
void logo_nextscene(void);
bool loaded_triangle = false;

/* m_logo - default logo screen, create unique "scenes" with a logo texture'd node with a timer */
mode m_logo = { M_LOGO_T, LOGO_SCENE_INIT, &logo_init, &logo_free, &logo_routine, &logo_nextscene };

/* init - setup graphics and memory objects */
void logo_init(void)
{
	int i;
	node *current_node;
	
	/* prepare graphics context */
	gfx_context.clearblack();	/* black background */
	
	/* allocate memory for scene objects */
	logo_scene = scene_init();
		scene_addnode(logo_scene, NT_TRIANGLE);
	
	for (i = 0; i < logo_scene->node_count; i++) {
		current_node = logo_scene->node_tree[i];
		switch (current_node->type) {
			case NT_TRIANGLE:
				nt_triangle_new(current_node);
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
	int i;
	
	for (i = 0; i < logo_scene->node_count; i++)
		logo_scene->node_tree[i]->free(logo_scene->node_tree[i]);

	scene_free(logo_scene);
	
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
	unsigned int i;
	unsigned int triangle_node;
	
	/* prepare graphics context */
	gfx_context.clearscreen();	/* black background */
	
	/* process mode-wide input */
	logo_input();
	
	/* process scene action */
	for (i = 0; i < logo_scene->node_count; i++)
		if (logo_scene->node_tree[i] != NULL && logo_scene->node_tree[i]->isactive == true)
			logo_scene->node_tree[i]->routine(logo_scene->node_tree[i]);
	
	/* prepare scene graphics */
	for (i = 0; i < logo_scene->node_count; i++)
		if (logo_scene->node_tree[i] != NULL && logo_scene->node_tree[i]->isrender == true)
			logo_scene->node_tree[i]->render(logo_scene->node_tree[i]);

	return;
}

/* nextscene - retain the current mode and load in another scene utilizing the same mode */
void logo_nextscene(void)
{
	return;
}
