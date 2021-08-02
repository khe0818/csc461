//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"

class Particle
{
public:
	friend class ParticleEmitter;

	Particle();
	~Particle();
	void Update(const float& time_elapsed);
	void CopyDataOnly(Particle *p);

private:
	Particle *next;
	Particle *prev;
	Vect4D	position;
	Vect4D	velocity;
	Vect4D	scale;
	float	life;
	float	rotation;
	float	rotation_velocity;


};


#endif 

// End of File
