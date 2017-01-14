/*	GLParticles	
*	video.c - Video function definitions
*	
*	Copyright 2017 Patrick Cland */

#include <SDL_opengl.h>
#include "video.h"
#include "particle.h"

const int		screenW = 640;
const int		screenH = 480;
const int		bpp		= 32;
const Uint32		flags	= SDL_OPENGL;

int initialize(int width, int height, int bpp, Uint32 flags)
{
	GLenum error;
	/* Set up screen */
	if(!SDL_SetVideoMode(width, height, bpp, flags))
	{
		printf("Error setting video: %s\n",SDL_GetError());
		return -1;
	}
	printf("Initialized video.\n");
	SDL_WM_SetCaption("GLParticles 0.1",NULL);

	/* Initialize OpenGL */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	error = glGetError();
	if(error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL: %s\n", gluErrorString(error));
		return -1;
	}
	printf("Initialized OpenGL\n");
	return 0;
}

void close(void)
{
	SDL_Quit();
}

void renderEmitter(Emitter e)
{
	glColor4f(r,g,b,a);
		glVertex2f(e.x - size, e.y + size);	/* top left */
		glVertex2f(e.x + size, e.y + size);	/* top right */
		glVertex2f(e.x + size, e.y - size);	/* bottom right */
		glVertex2f(e.x - size, e.y - size);	/* bottom left */
}

void renderParticles(Particle* p)
{
	int i;
	glColor4f(r,g,b,a);
	for(i = 0; i < PARTICLE_LIMIT; i++)
	{
		glVertex2f(p[i].x - size , p[i].y + size);
		glVertex2f(p[i].x + size , p[i].y + size);
		glVertex2f(p[i].x + size , p[i].y - size);
		glVertex2f(p[i].x - size , p[i].y - size);
	}
}

void renderUI()
{
	float xO = 5;		/* X offset */
	float yO = 370;		/* Y offset */
	float xW = 150;		/* width */
	float yW = 12;		/* height */
	/* Render the color bars */
	/* red */
	glColor4f(1.0f,0.0f,0.0f,1.0f);
	glRectf(xO, yO, xO + ((r * xW)/MAX_COLOR), yO+yW);
	/* green */
	glColor4f(0.0f,1.0f,0.0f,1.0f);
	glRectf(xO, yO+yW, xO + ((g * xW)/MAX_COLOR), yO+(yW*2));
	/* blue */
	glColor4f(0.0f,0.0f,1.0f,1.0f);
	glRectf(xO, yO+(yW*2), xO + ((b * xW)/MAX_COLOR), yO+(yW*3));
	/* alpha */
	glColor4f(1.0f,1.0f,0.0f,1.0f);
	glRectf(xO, yO+(yW*3), xO + ((a * xW)/MAX_COLOR), yO+(yW*4));

	glColor4f(1.0f,1.0f,1.0f,1.0f);
	/* gravity */
	glRectf(xO, yO+(yW*4+1), xO + ((grav * xW)/MAX_GRAV), yO+(yW*5));
	/* velocity */
	glRectf(xO, yO+(yW*5+1), xO + ((vel * xW)/MAX_VEL), yO+(yW*6));
	/* angle */ 
	glRectf(xO, yO+(yW*6+1), xO + ((ang * xW)/MAX_ANGLE), yO+(yW*7));
	/* size */
	glRectf(xO, yO+(yW*7+1), xO + ((size * xW)/MAX_SIZE), yO+(yW*8));
	/* death rate */
	glRectf(xO, yO+(yW*8+1), xO + ((deathRate * xW)/MAX_DEATH_RATE), yO+(yW*9));

}
