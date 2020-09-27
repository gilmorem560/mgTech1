/*
 * glcontext - OpenGL context 
 */
#include "glcontext.h"

void gl_clearblack(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	return;
}

void gl_setprops(enum gfx_props properties)
{
	if (properties & GFX_PROPS_DEPTH_BUFFER)
		glEnable(GL_DEPTH_TEST);
}

void gl_clearscreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return;
}

void gl_position(float x, float y, float z)
{
	glTranslatef(x, y, z);
	return;
}

void gl_setprj(double left, double right, double bottom, double top, double nearVal, double farVal)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(left, right, bottom, top, nearVal, farVal);
	return;
}

void gl_setortho(double left, double right, double bottom, double top, double nearVal, double farVal)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, nearVal, farVal);
	return;
}

void gl_modelinit(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return;
}
