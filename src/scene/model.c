/*
 * model - a model representing a node
 */
#include "model.h"

model *model_new(unsigned int type)
{
	model *this = malloc(sizeof (model));
		this->type = type;
		this->routine = NULL;
		this->render = NULL;
	
	return this;
}
void model_free(model *this)
{
	free(this);
	
	return;
}
