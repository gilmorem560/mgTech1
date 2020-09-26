/*
 * sound-alsa - alsa sound subsystem for linux
 */
#ifndef __SOUND_ALSA_H__
#define __SOUND_ALSA_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "sound.h"
typedef sndcontext alsacontext;

#include <alsa/asoundlib.h>

extern const alsacontext snd_context;
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __SOUND_ALSA_H__ */
