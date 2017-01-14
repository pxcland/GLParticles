/*	GLParticles	
*	input.c - Keypress handling routines
*	
*	Copyright 2017 Patrick Cland */

#include <SDL.h>
#include "particle.h"
#include "input.h"

Uint8* key = 0;

void processInput(Uint8* key, Emitter* e)
{
	key = SDL_GetKeyState(NULL);
	/* Handle key presses for up and down */
	if(key[SDLK_UP])
		e->yV -= EMITTER_VEL;
	else if(!key[SDLK_UP])
		if(e->yV < 0.0f)
			e->yV = 0.0f;
	if(key[SDLK_DOWN])
		e->yV += EMITTER_VEL;
	else if(!key[SDLK_DOWN])
		if(e->yV > 0.0f)
			e->yV = 0.0f;

	/* Handle key presses for left and right */
	if(key[SDLK_LEFT])
		e->xV -= EMITTER_VEL;
	else if(!key[SDLK_LEFT])
		if(e->xV < 0.0f)
			e->xV = 0.0f;
	if(key[SDLK_RIGHT])
		e->xV += EMITTER_VEL;
	else if(!key[SDLK_RIGHT])
		if(e->xV > 0.0f)
			e->xV = 0.0f;

	/* Handle key presses for the controls */
	/* Angle */
	if(key[SDLK_z])
		e->angV -= EMITTER_ANGV;
	else if(!key[SDLK_z])
		if(e->angV < 0.0f)
			e->angV = 0.0f;
	if(key[SDLK_x])
		e->angV += EMITTER_ANGV;
	else if(!key[SDLK_x])
		if(e->angV > 0.0f)
			e->angV = 0.0f;

	/* Velocity */
	if(key[SDLK_a])
		e->velV -= EMITTER_VELV;
	else if(!key[SDLK_a])
		if(e->velV < 0.0f)
			e->velV = 0.0f;
	if(key[SDLK_s])
		e->velV += EMITTER_VELV;
	else if(!key[SDLK_s])
		if(e->velV > 0.0f)
			e->velV = 0.0f;

	/* Gravity */
	if(key[SDLK_q])
		e->gravV -= EMITTER_GRAVV;
	else if(!key[SDLK_q])
		if(e->gravV < 0.0f)
			e->gravV = 0.0f;
	if(key[SDLK_w])
		e->gravV += EMITTER_GRAVV;
	else if(!key[SDLK_w])
		if(e->gravV > 0.0f)
			e->gravV = 0.0f;

	/* Size */
	if(key[SDLK_1])
		e->sizeV -= EMITTER_SIZEV;
	else if(!key[SDLK_1])
		if(e->sizeV < 0.0f)
			e->sizeV = 0.0f;
	if(key[SDLK_2])
		e->sizeV += EMITTER_SIZEV;
	else if(!key[SDLK_2])
		if(e->sizeV > 0.0f)
			e->sizeV = 0.0f;

	/* Colors */
	/* Red */
	if(key[SDLK_3])
		e->rV -= EMITTER_COLV;
	else if(!key[SDLK_3])
		if(e->rV < 0.0f)
			e->rV = 0.0f;
	if(key[SDLK_4])
		e->rV += EMITTER_COLV;
	else if(!key[SDLK_4])
		if(e->rV > 0.0f)
			e->rV = 0.0f;

	/* Green */
	if(key[SDLK_5])
		e->gV -= EMITTER_COLV;
	else if(!key[SDLK_5])
		if(e->gV < 0.0f)
			e->gV = 0.0f;
	if(key[SDLK_6])
		e->gV += EMITTER_COLV;
	else if(!key[SDLK_6])
		if(e->gV > 0.0f)
			e->gV = 0.0f;

	/* Blue */
	if(key[SDLK_7])
		e->bV -= EMITTER_COLV;
	else if(!key[SDLK_7])
		if(e->bV < 0.0f)
			e->bV = 0.0f;
	if(key[SDLK_8])
		e->bV += EMITTER_COLV;
	else if(!key[SDLK_8])
		if(e->bV > 0.0f)
			e->bV = 0.0f;

	/* Alpha */
	if(key[SDLK_9])
		e->aV -= EMITTER_COLV;
	else if(!key[SDLK_9])
		if(e->aV < 0.0f)
			e->aV = 0.0f;
	if(key[SDLK_0])
		e->aV += EMITTER_COLV;
	else if(!key[SDLK_0])
		if(e->aV > 0.0f)
			e->aV = 0.0f;

	/* Death Rate */
	if(key[SDLK_MINUS])
		e->deathRateV -= EMITTER_DEATHRATEV;
	else if(!key[SDLK_MINUS])
		if(e->deathRateV < 0.0f)
			e->deathRateV = 0.0f;
	if(key[SDLK_EQUALS])
		e->deathRateV += EMITTER_DEATHRATEV;
	else if(!key[SDLK_EQUALS])
		if(e->deathRateV > 0.0f)
			e->deathRateV = 0.0f;

	/* Amount Emitting Rate */
	/*
	if(key[SDLK_COMMA])
		e->emittingAmountV -= EMITTER_EMITTINGV;
	else if(!key[SDLK_COMMA])
		if(e->emittingAmountV < 0.0f)
			e->emittingAmountV = 0.0f;
	if(key[SDLK_PERIOD])
		e->emittingAmountV += EMITTER_EMITTINGV;
	else if(!key[SDLK_PERIOD])
		if(e->emittingAmountV > 0.0f)
			e->emittingAmountV = 0.0f;
	*/
}