/*	GLParticles	
*	particle.h - Particle related declarations
*	
*	Copyright 2017 Patrick Cland */

#ifndef PARTICLE_H
#define PARTICLE_H


#define PARTICLE_LIMIT	3000
#define TICK_RATE		0.2f
#define MAX_LIFE		5000

#define MAX_ANGLE		6.28f	/* 2ƒÎ radians */
#define MAX_GRAV		0.2f
#define MAX_VEL			5.0f
#define MAX_SIZE		10.0f
#define MAX_DEATH_RATE	10.0f

#define MAX_COLOR		1.0f
/* Particles have the following attributes:
Angle:		Angle from 0-2ƒÎ at which they are launched
Velocity:	Velocity at which they are launched
Gravity:	Gravity which they experience (how fast they fall)
Size:		Size of particle (dimension of square)
Color:		Color of particle 
Position:	Where they are located on the screen
Life:		How long the particle has to live
Death Rate:	How fast the particle dies */

extern float r, g, b, a;
extern float vel, grav, ang;
extern float size;
extern float deathRate;
extern float emittingAmount;

typedef enum _isEmitting {NOT_EMITTING, EMITTING} isEmitting;

typedef struct _Particle
{
	float life;		/* How long a particle has to live */
	float angle;	/* Each particle will have a randomized angle in a range */
	float grav;
	float vel;

	float x;		/* Position */
	float y;

	float tick;		/* Each tick the particle is updated */
} Particle;

typedef struct _Emitter
{
	float x;
	float y;

	/* Modifiers for particle attributes */
	float xV;
	float yV;
	float angV;		
	float velV;
	float gravV;
	float sizeV;
	float rV;
	float gV;
	float bV;
	float aV;
	float deathRateV;
	float emittingAmountV;

	isEmitting emittingStatus;

} Emitter;

void initEmitter(Emitter* e, float x, float y, float xV, float yV, float angV, float velV, float gravV, float sizeV, float rV, \
					float gV, float bV, float aV, float deathRateV, float emittingAmountV, isEmitting emittingStatus);
void initParticles(Particle* p, Emitter e);
void updateParticles(Particle* p, Emitter e);
void updateEmitter(Emitter* e);

#endif
