/*
 * sound-alsa - alsa sound subsystem for linux
 */
#include "sound-alsa.h"

void alsa_init(void);
void alsa_free(void);

const alsacontext snd_context = { &alsa_init, &alsa_free };

static snd_output_t *output = NULL;
static snd_pcm_t *pcm = NULL;

void alsa_init(void)
{
	int err;
	snd_pcm_hw_params_t *hwparams;
	snd_pcm_sw_params_t *swparams;

	snd_pcm_hw_params_alloca(&hwparams);
	snd_pcm_sw_params_alloca(&swparams);
	
	/* connect to stdout for logging */
	if ((err = snd_output_stdio_attach(&output, stdout, 0)) < 0) {
		fprintf(stderr, "%s\n", snd_strerror(err));
		exit(EXIT_FAILURE);
	}
	
	/* open the PCM device */
	if ((err = snd_pcm_open(&pcm, "hw:1,0", SND_PCM_STREAM_PLAYBACK, SND_PCM_NONBLOCK)) < 0) {
		fprintf(stderr, "%s\n", snd_strerror(err));
		exit(EXIT_FAILURE);
	}
	
	#ifndef NDEBUG
	puts("alsa_init: complete");
	#endif /* NDEBUG */
	
	return;
}

void alsa_free(void)
{
	snd_pcm_close(pcm);
	
	#ifndef NDEBUG
	puts("alsa_free: complete");
	#endif /* NDEBUG */
	
	return;
}
