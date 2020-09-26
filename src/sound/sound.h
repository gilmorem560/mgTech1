/*
 * sound - sound subsystem
 */
#ifndef __SOUND_H__
#define __SOUND_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
#include "../common.h"
	
typedef struct sndcontext {
	void (*init)(void);
	void (*free)(void);
} sndcontext;

#if SND_BACKEND == SND_ALSA
#include "sound-alsa.h"
#elif SND_BACKEND == SND_WND
#include "sound-win.h"
#endif /* SND_BACKEND */
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __SOUND_H__ */
