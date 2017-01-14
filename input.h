/*	GLParticles	
*	input.h - Program control header file
*	
*	Copyright 2017 Patrick Cland */

#ifndef INPUT_H
#define INPUT_H

extern Uint8* key;

#define EMITTER_VEL         0.0001f
#define EMITTER_ANGV        0.000005f
#define EMITTER_VELV        0.000005f
#define EMITTER_GRAVV       0.000001f
#define EMITTER_COLV        0.000001f
#define EMITTER_SIZEV       0.000005f
#define EMITTER_DEATHRATEV  0.000001f
#define	EMITTER_EMITTINGV   0.00002f

void processInput(Uint8* key, Emitter* e);

#endif
