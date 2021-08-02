//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "DO_NOT_MODIFY\OpenGLInterface.h"
#include "Framework.h"

#include "ParticleEmitter.h"
#include "Settings.h"

extern Timer GlobalTimer;

static const unsigned char squareColors[] =
{
	200,  200,  0,  255, // Color   
	200,  200,  0,  255, // Color   
	200,  200,  0,  255, // Color   
	200,  200,  0,  255, // Color   
};

static const float squareVertices[] =
{
	-0.015f,  -0.015f, 0.0f, // Size of Triangle  
	 0.015f,  -0.015f, 0.0f, // Size of Triangle  
	-0.015f,   0.015f, 0.0f, // Size of Triangle  
	 0.015f,   0.015f, 0.0f, // Size of Triangle  
};

ParticleEmitter::ParticleEmitter()
	: start_position(0.0f, 0.0f, 0.0f),
	start_velocity(0.0f, 1.0f, 0.0f),
	max_life(MAX_LIFE),
	max_particles(NUM_PARTICLES),
	spawn_frequency(0.0000001f),
	last_active_particle(-1),
	vel_variance(1.0f, 4.0f, 0.4f),
	pos_variance(1.0f, 1.0f, 1.0f),
	scale_variance(2.5f),
	headParticle(0)
{
	GlobalTimer.Toc();

	last_spawn = GlobalTimer.TimeInSeconds();
	last_loop = GlobalTimer.TimeInSeconds();
}



ParticleEmitter::~ParticleEmitter()
{
	// do nothing
}

void ParticleEmitter::SpawnParticle()
{
	// create another particle if there are ones free
	if (last_active_particle < max_particles - 1)
	{

		// create new particle
		Particle *newParticle = new Particle();

		// initialize the particle
		newParticle->life = 0.0f;
		newParticle->position = start_position;
		newParticle->velocity = start_velocity;
		newParticle->scale = Vect4D(2.0f, 2.0f, 2.0f, 1.0f);

		// apply the variance
		this->Execute(newParticle->position, newParticle->velocity, newParticle->scale);

		// increment count
		last_active_particle++;

		// add to list
		this->addParticleToList(newParticle);

	}
}

void ParticleEmitter::update()
{
	// get current time
	GlobalTimer.Toc();
	float current_time = GlobalTimer.TimeInSeconds();

	// spawn particles
	float time_elapsed = current_time - last_spawn;

	// update
	while (spawn_frequency < time_elapsed)
	{
		// spawn a particle
		this->SpawnParticle();
		// adjust time
		time_elapsed -= spawn_frequency;
		// last time
		last_spawn = current_time;
	}

	// total elapsed
	time_elapsed = current_time - last_loop;

	Particle *p = this->headParticle;
	// walk the particles
	Particle *s;
	while (p != nullptr)
	{
		// call every particle and update its position 
		p->Update(time_elapsed);

		// if it's live is greater that the max_life 
		// and there is some on the list
		// remove node
		if ((p->life > max_life) && (last_active_particle > 0))
		{
			// particle to remove
			s = p;

			// need to squirrel it away.

			// remove last node
			this->removeParticleFromList(s);

			// update the number of particles
			last_active_particle--;
		}
			// increment to next point
			p = p->next;

	}

	//move a copy to vector for faster iterations in draw
	p = this->headParticle;
	bufferCount = 0;

	// clear the buffer
	//drawBuffer.clear();

	// walk the pointers, add to list
	while (p != nullptr)
	{
		// add to buffer
		p->CopyDataOnly(p);
		// advance ptr
		p = p->next;

		// track the current count
		bufferCount++;
	}

	// make sure the counts track (asserts go away in release - relax Christos)
	assert(bufferCount == (last_active_particle + 1));
	last_loop = current_time;
}

void ParticleEmitter::addParticleToList(Particle *p)
{
	assert(p);
	if (this->headParticle != 0)
	{ // add to front of list
		headParticle->prev = p;
		p->next = headParticle;
		p->prev = 0;
		headParticle = p;
	}
	else
	{ // first on list
		this->headParticle = p;
		p->next = 0;
		p->prev = 0;
	}

}

void ParticleEmitter::removeParticleFromList(Particle *p)
{
	// make sure we are not screwed with a null pointer
	//assert(p);
	if (p->prev != 0 && p->next == 0)
	{ // last on the list 
	p->prev->next = 0;
	
	}
	else if( p->next != 0  && p->prev !=0 )
	{ // middle of the list
	p->prev->next = p->next;
	p->next->prev = p->prev;
	}
	else if (p->prev == 0 && p->next != 0)
	{ // first on the list
		p->next->prev = 0;
		this->headParticle = p->next;
		
	}
	else
	{ // only one on the list
		this->headParticle = 0;
	}
	

	// bye bye
	
}



void ParticleEmitter::draw()
{
	// get the camera matrix from OpenGL
	// need to get the position
	Matrix cameraMatrix;

	// get the camera matrix from OpenGL
	glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<float*>(&cameraMatrix));
	// OpenGL goo... don't worrry about this
	glVertexPointer(3, GL_FLOAT, 0, squareVertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);
	glEnableClientState(GL_COLOR_ARRAY);
	// iterate throught the list of particles

	// get the position from this matrix
	Vect4D camPosVect;
	cameraMatrix.get(&camPosVect);
	// camera position
	Matrix transCamera;
	Matrix scaleMatrix;
	Matrix rotParticle;
	Matrix transParticle;
	Matrix tmp;
	transCamera.setTransMatrix(&camPosVect);
	Particle* it = this->headParticle;
	/*Timer startTimer;
	startTimer.Tic();*/
	while(it!= nullptr)
	{
		//Temporary matrix
	
		// particle position
		
		transParticle.setTransMatrix(&it->position);
		rotParticle.setRotZMatrix(it->rotation);
		scaleMatrix.setScaleMatrix(&it->scale);
		tmp = scaleMatrix * transCamera * transParticle * rotParticle * scaleMatrix;
		glLoadMatrixf(reinterpret_cast<float*>(&(tmp)));
		// squirrel away matrix for next update
		// draw the trangle strip
				// squirrel away matrix for next update

		// draw the trangle strip
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		// difference vector
		// difference vector
		it = it->next;
	}
	/*startTimer.Toc();
	float StartTimer = startTimer.TimeInSeconds();
	printf("LoopTime: StartTimer:%f ms\n", StartTimer *1000.0f);*/
	free(it);
	// delete the buffer
	// done with buffer, clear it.
}

void ParticleEmitter::Execute(Vect4D& pos,  Vect4D& vel, Vect4D& sc)
{
	// Add some randomness...

	// Ses it's ugly - I didn't write this so don't bitch at me   
	// Sometimes code like this is inside real commerical code   
	// ( so now you know how it feels )   

	// x - variance
	float var = static_cast<float>(rand() % 1000) * 0.001f; // Var           
	float sign = static_cast<float>(rand() % 2);  // Sign          
	float *t_pos = reinterpret_cast<float*>(&pos);
	float *t_var = &pos_variance[x];
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// y - variance
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// z - variance
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);

	// x  - add velocity
	t_pos = &vel[x];
	t_var = &vel_variance[x];
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// y - add velocity
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// z - add velocity
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// correct the sign
	var = 2.0f * static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);

	if (sign == 0)
	{
		var *= -1.0f;
	}
	sc = sc * var;
}


void ParticleEmitter::GoodBye()
{
	Particle *pTmp = this->headParticle;
	Particle *pDeadMan = nullptr;
	while (pTmp)
	{
		pDeadMan = pTmp;
		pTmp = pTmp->next;
		delete pDeadMan;
	}
}

// End of file
