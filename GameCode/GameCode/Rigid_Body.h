#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include"Vector.h"

#define universal_mass 1.0f
#define universal_gravity 9.8f

#define fwd  1
#define bwd -1

#define up -1
#define down 1

class Rigid_Body
{

public:
	Rigid_Body()
	{
		m_Mass = universal_mass;
		m_Gravity = universal_gravity;
	}

	//general
	inline void SetMass(float mass) { m_Mass = mass; }
	inline void SetGravity(float gravity) { m_Gravity = gravity; }

	//forte aux

	inline void ApplyForce(Vector F) { Force = F; }
	inline void ApplyForce_X(Vector F) { Force.X = F.X; }
	inline void ApplyForce_Y(Vector F) { Force.Y = F.Y; }
	inline void RemoveForce() { Force = Vector(0,0); }

	//frecare

	inline void ApplyFriction(Vector FF) { Friction_Force = FF; }
	inline void RemoveFriction() { Friction_Force = Vector(0, 0); }

	//its physics time(please end me)

	void Update(float d)
	{
		m_Acceleration.X = (Force.X + Friction_Force.X) / m_Mass;
		m_Acceleration.Y = m_Gravity + Force.Y / m_Mass;

		m_Velocity = m_Acceleration * d;
		m_Position = m_Velocity * d;

	}

	//acces direct ;)

	inline float GetMass() { return m_Mass; }
	inline Vector GetPosition() { return m_Position; }
	inline Vector GetVelocity() { return m_Velocity; }
	inline Vector GetAcceleration() { return m_Acceleration; }


private:
	
	float m_Mass, m_Gravity;

	Vector Force;
	Vector Friction_Force;

	Vector m_Position;
	Vector m_Velocity;
	Vector m_Acceleration;

};


#endif

