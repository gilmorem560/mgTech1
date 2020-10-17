/*
 * triangle - a simple triangle model
 */  
#include "models.h"

/* debug GLX */
#include <GL/gl.h>
#include <GL/glx.h>

static void mt_triangle_routine(void);
static void mt_triangle_render(void);

void mt_logo_triangle_new(model *this)
{
	this->routine = &mt_triangle_routine;
	this->render = &mt_triangle_render;
}

void mt_triangle_routine(void)
{
	return;
}

void mt_triangle_render(void)
{
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
	glEnd();
	
	return;
}
