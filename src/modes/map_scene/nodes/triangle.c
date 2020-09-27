/*
 * triangle - a simple triangle
 */
#include "nodes.h"
#include "../../../graphics/graphics.h"
#include "../../../input/input.h"
#include "../models/models.h"

static void nt_triangle_init(node *this);
static void nt_triangle_routine(node *this);
static void nt_triangle_render(node *this);
static void nt_triangle_free(node *this);

void nt_map_triangle_new(node *this)
{
	this->init = &nt_triangle_init;
	this->routine = &nt_triangle_routine;
	this->render = &nt_triangle_render;
	this->free = &nt_triangle_free;
	
	this->position.x = 0.0;
	this->position.y = 0.0;
	this->position.z = 0.0;
}

void nt_triangle_init(node *this)
{
	this->isactive = true;
	this->isrender = true;
	mt_map_triangle_new(this->geom);
	return;
}

void nt_triangle_routine(node *this)
{
	if (i_keyheld & KEY_A)
		this->position.x -= 0.01f;
	if (i_keyheld & KEY_D)
		this->position.x += 0.01f;
	
	if (i_keyheld & KEY_W)
		this->position.y += 0.01f;
	if (i_keyheld & KEY_S)
		this->position.y -= 0.01f;
	
	return;
}

void nt_triangle_render(node *this)
{
	if (this->geom != NULL) {
		gfx_context.startmatrix();
		gfx_context.position(this->position.x, this->position.y, this->position.z);
		this->geom->render();
		gfx_context.stopmatrix();
	}
}

void nt_triangle_free(node *this)
{
	return;
}
