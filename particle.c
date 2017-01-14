/*	GLParticles	
*	particle.c - Particle implementation
*	
*	Copyright 2017 Patrick Cland */

#include <stdlib.h>
#include <math.h>
#include "particle.h"
#include "video.h"

/* Default values for emitter */
float r = 0.3f, g = 0.3f, b = 0.7f, a = 0.5f;
float vel = 2.5f, grav = 0.05f, ang = (3.14f/4.0f);	/* ƒÎ/4 rad */
float size = 5.0f;
float deathRate = 1.0f;
float emittingAmount = 3000.0f;

void initEmitter(Emitter* e, float x, float y, float xV, float yV, float angV, float velV, float gravV, float sizeV, float rV, \
					float gV, float bV, float aV, float deathRateV, float emittingAmountV, isEmitting emittingStatus)
{
	e->x = x;
	e->y = y;
	e->xV = xV;
	e->yV = yV;
	e->angV = angV;
	e->velV = velV;
	e->gravV = gravV;
	e->sizeV = sizeV;
	e->rV = rV;
	e->gV = gV;
	e->bV = bV;
	e->aV = aV;
	e->deathRateV = deathRateV;
	e->emittingAmountV = emittingAmountV;
	e->emittingStatus = emittingStatus;
}

void initParticles(Particle* p, Emitter e)
{
	int i;
	for(i = 0; i < PARTICLE_LIMIT; i++)
	{
		p[i].life	= (float)(rand() % MAX_LIFE);
		p[i].angle	= (float)(((rand() % 1) * 0.0005f) + ang);
		p[i].vel	= vel;
		p[i].grav	= grav;
		p[i].tick	= 0.0f;
		p[i].x		= e.x;
		p[i].y		= e.y;
	}
}

void updateParticles(Particle* p, Emitter e)
{
	int i;
	for(i = 0; i < emittingAmount; i++)
	{
		p[i].x += (float)((p[i].vel * cos(p[i].angle) * p[i].tick)/800.0f);
		p[i].y -= (float)((p[i].vel * sin(p[i].angle) * p[i].tick) - (0.5f * p[i].grav * p[i].tick * p[i].tick))/800.0f;
		p[i].tick += TICK_RATE;
		p[i].life -= deathRate;

		/* Once the particle dies, reset it */
		if(p[i].life <= 0 && e.emittingStatus == EMITTING)
		{
			p[i].x		= e.x;
			p[i].y		= e.y;
			p[i].life	= (float)(rand() % MAX_LIFE);
			p[i].angle	= (float)((rand() % 100) * 0.0075f) + ang;
			p[i].vel	= vel;
			p[i].grav	= grav;
			p[i].tick	= 0.0f;
		}
	}
}

void updateEmitter(Emitter* e)
{
	e->x += e->xV;
	e->y += e->yV;

	ang += e->angV;
	/* 2ƒÎ wraps to 0 and vice versa */
	if(ang > MAX_ANGLE)
		ang = 0;
	else if(ang < 0)
		ang = MAX_ANGLE;

	vel += e->velV;
	if(vel > MAX_VEL)
		vel = MAX_VEL;
	else if(vel < 0)
		vel = 0;

	grav += e->gravV;
	if(grav > MAX_GRAV)
		grav = MAX_GRAV;
	else if(grav < 0)
		grav = 0;

	r += e->rV;
	if(r > MAX_COLOR)
		r = MAX_COLOR;
	else if(r < 0)
		r = 0;

	g += e->gV;
	if(g > MAX_COLOR)
		g = MAX_COLOR;
	else if(g < 0)
		g = 0;

	b += e->bV;
	if(b > MAX_COLOR)
		b = MAX_COLOR;
	else if(b < 0)
		b = 0;

	a += e->aV;
	if(a > MAX_COLOR)
		a = MAX_COLOR;
	else if(a < 0)
		a = 0;

	size += e->sizeV;
	if(size > MAX_SIZE)
		size = MAX_SIZE;
	else if(size < 0)
		size = 0;

	deathRate += e->deathRateV;
		if(deathRate > MAX_DEATH_RATE)
			deathRate = MAX_DEATH_RATE;
		else if(deathRate < 0)
			deathRate = 0;

	emittingAmount += e->emittingAmountV;
		if(emittingAmount >= PARTICLE_LIMIT)
			emittingAmount = PARTICLE_LIMIT;
		else if(emittingAmount < 0)
			emittingAmount = 0;

	/* Check emitter collision against window edge */
	if(e->x < 0)
		e->x = 0;
	else if(e->x > (float)screenW)
		e->x = (float)screenW;
	else if(e->y < 0)
		e->y = 0;
	else if(e->y > (float)screenH)
		e->y = (float)screenH;	
}