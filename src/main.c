/*
 * mgTech1 - main routine
 */
#include "common.h"
#include "graphics/graphics.h"
#include "sound/sound.h"
#include "input/input.h"
#include "modes/modes.h"

#ifndef NDEBUG
bool f_debug = true;
#else
bool f_debug = false;
#endif /* NDEBUG */
bool f_running = true;
mode *f_mode = &init_mode;
int f_prevmode_t = INIT_MODE;
int f_prevscene_index_t = INIT_SCENE;

/* main - entrypoint */
int main(int argc, char *argv[])
{
	#if HAS_COMMAND_ARGS == 1
	char c;
	#endif /* HAS_COMMAND_ARGS */
	
	#if HAS_COMMAND_ARGS == 1
	if (argc > 2) {
		fprintf(stderr, "%s -[d]\n", argv[0]);
		fputs("\td: debug mode\n", stderr);
		return EXIT_FAILURE;
	}
	
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'd':
				f_debug = true;
				break;
			default:
				fprintf(stderr, "unrecognized option: %c\n", c);
				break;
			}
	#endif /* HAS_COMMAND_ARGS */
			
	if (f_debug) puts("mgTech1 starting in debug mode");
	
	gfx_context.init();
	snd_context.init();
	input_context.init();
	f_mode->init();
	
	while (f_running) {
		input_context.poll();
		f_mode->routine();
		gfx_context.draw();
		
		if (!f_running) continue;
		
		if (f_mode->type != f_prevmode_t) {							/* switch modes */
			f_mode->free();
			f_mode->init();
			f_prevmode_t = f_mode->type;
		} else if (f_mode->scene_index != f_prevscene_index_t) {	/* switch scene index */
			f_mode->nextscene();
			f_prevscene_index_t = f_mode->scene_index;
		}
	}
	
	f_mode->free();
	input_context.free();
	snd_context.free();
	gfx_context.free();
	
	return EXIT_SUCCESS;
}
