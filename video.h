/*	GLParticles	
*	video.h - Video function header file
*	
*	Copyright 2017 Patrick Cland */

#ifndef VIDEO_H
#define VIDEO_H
#include <SDL.h>
#include "particle.h"


extern const int	screenW;
extern const int	screenH;
extern const int	bpp;
extern const Uint32	flags;

int initialize(int width, int height, int bpp, Uint32 flags);
void close(void);
void renderEmitter(Emitter e);
void renderParticles(Particle* p);
void renderUI();

#endif
