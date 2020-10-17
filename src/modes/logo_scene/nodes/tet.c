/*
 * tet - a simple tet
 */
#include "nodes.h"
#include "../models/models.h"
#include "../../../graphics/graphics.h"
#include "../../../input/input.h"

static void nt_tet_init(node *this);
static void nt_tet_routine(node *this);
static void nt_tet_render(node *this);
static void nt_tet_free(node *this);

void nt_logo_tet_new(node *this)
{
	this->init = &nt_tet_init;
	this->routine = &nt_tet_routine;
	this->render = &nt_tet_render;
	this->free = &nt_tet_free;
	
	this->angle.x = 0.0f;
	this->angle.y = 1.0f;
	this->angle.z = 0.0f;
	
	this->rot = 0.0f;
}

void nt_tet_init(node *this)
{
	this->isactive = true;
	this->isrender = true;
	mt_logo_tet_new(this->geom);
	return;
}

void nt_tet_routine(node *this)
{
	if (i_keyheld & KEY_A)
		this->position.x -= 0.01f;
	if (i_keyheld & KEY_D)
		this->position.x += 0.01f;
	
	if (i_keyheld & KEY_W)
		this->position.z += 0.01f;
	if (i_keyheld & KEY_S)
		this->position.z -= 0.01f;
	
	this->rot += 0.2f;
	this->rot = fmod(this->rot, 360.0f);
	
	return;
}

void nt_tet_render(node *this)
{
	if (this->geom != NULL) {
		gfx_context.startmatrix();
		gfx_context.position(this->position.x, this->position.y, this->position.z);
		gfx_context.rotate(this->rot, this->angle.x, this->angle.y, this->angle.z);
		this->geom->render();
		gfx_context.stopmatrix();
	}
}

void nt_tet_free(node *this)
{
	return;
}
