/*
 * triangle - a simple triangle
 */
#include "nodes.h"
#include "../../../graphics/graphics.h"
#include "../../../input/input.h"

void nt_triangle_init(node *this);
void nt_triangle_routine(node *this);
void nt_triangle_render(node *this);
void nt_triangle_free(node *this);

typedef struct triangle_props {
	float pos_x, pos_y, pos_z;
} triangle_props;

void nt_triangle_new(node *this)
{
	triangle_props *properties;
	this->init = &nt_triangle_init;
	this->routine = &nt_triangle_routine;
	this->render = &nt_triangle_render;
	this->free = &nt_triangle_free;
	properties = malloc(sizeof (triangle_props));
	
	properties->pos_x = 0.0f;
	properties->pos_y = 0.0f;
	properties->pos_z = 0.0f;
	
	this->properties = properties;
}

void nt_triangle_init(node *this)
{
	this->isactive = true;
	this->isrender = true;
	mt_triangle_new(this->geom);
	return;
}

void nt_triangle_routine(node *this)
{
	if (i_keyheld & KEY_A)
		((triangle_props *) this->properties)->pos_x -= 0.01;
	if (i_keyheld & KEY_D)
		((triangle_props *) this->properties)->pos_x += 0.01;
	
	if (i_keyheld & KEY_W)
		((triangle_props *) this->properties)->pos_y += 0.01;
	if (i_keyheld & KEY_S)
		((triangle_props *) this->properties)->pos_y -= 0.01;
	
	return;
}

void nt_triangle_render(node *this)
{
	if (this->geom != NULL)
		gfx_context.startmatrix();
		gfx_context.position(((triangle_props *) this->properties)->pos_x, ((triangle_props *) this->properties)->pos_y, ((triangle_props *) this->properties)->pos_z);
		this->geom->render();
		gfx_context.stopmatrix();
}

void nt_triangle_free(node *this)
{
	free(this->properties);
	return;
}
