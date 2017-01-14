/*	GLParticles	
*	main.c - Program Entry Point
*	
*	Copyright 2017 Patrick Cland */

#include <stdio.h>
#include <time.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "video.h"
#include "particle.h"
#include "input.h"

int main(int argc, char* argv[])
{
	Particle	particles[PARTICLE_LIMIT];
	Emitter		emitter;
	SDL_Event	event;

	srand((unsigned) time(NULL));

	SDL_Init(SDL_INIT_EVERYTHING);

	if(initialize(screenW, screenH, bpp, flags) == -1)
	{
		printf("Error initializing. Exiting...\n");
		close();
		return -1;
	}
	printf("Initialized emitter.\n");

	initEmitter(	&emitter,
			screenW/2.0f,
			screenH/2.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			EMITTING);

	initParticles(particles,emitter);

	/* Main particle emitter loop */
	while(1)
	{
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				close();
				return 0;
			}
			if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_SPACE:
						if(emitter.emittingStatus == NOT_EMITTING)
						{
							emitter.emittingStatus = EMITTING;
							initParticles(particles,emitter);
						}
						else
							emitter.emittingStatus = NOT_EMITTING;
						break;
					default:
						break;
				}
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);
		processInput(key,&emitter);
		updateEmitter(&emitter);
		
		glBegin(GL_QUADS);
			renderEmitter(emitter);
			updateParticles(particles,emitter);
			renderParticles(particles);
		glEnd();
		renderUI();
		SDL_GL_SwapBuffers();
	}
}
