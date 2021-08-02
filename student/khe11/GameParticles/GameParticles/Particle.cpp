//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Particle.h"
#include "Matrix.h"

Vect4D z_axis(0.0f, -0.25f, 1.0f);
Vect4D v(3.0f, 4.0f, 0.0f);

Particle::Particle()
{
	// construtor
	this->life = 0.0f;
	this->position.set(0.0f, 0.0f, 0.0f);
	this->velocity.set(0.0f, 0.0f, 0.0f);
	this->scale.set(1.0f, 1.0f, 1.0f);
	this->rotation = 0.0f;
	this->rotation_velocity = -0.5f;
}

Particle::~Particle()
{
	// nothing to do
}

void Particle::CopyDataOnly(Particle *p)
{
	// copy the data only
	// this way of copying data is more efficient that element by element
	this->position = p->position;
	this->velocity = p->velocity;
	this->scale = p->scale;
	this->rotation = p->rotation;
	this->rotation_velocity = p->rotation_velocity;
	this->life = p->life;
}

void Particle::Update(const float& time_elapsed)
{
	life += time_elapsed;
	position += (velocity * time_elapsed);
	position.Cross(z_axis, v);
	v.Norm(v);
	position += v * 0.05f * life;
	rotation += rotation_velocity * time_elapsed *2.01f;
}


// End of file
