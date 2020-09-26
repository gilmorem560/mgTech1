/*
 * glcontext - OpenGL context 
 */
#include "glcontext.h"

void gl_clearblack(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	return;
}

void gl_clearscreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	return;
}

void gl_position(float x, float y, float z)
{
	glTranslatef(x, y, z);
	return;
}
