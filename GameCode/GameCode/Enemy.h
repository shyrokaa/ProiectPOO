#ifndef ENEMY_H
#define ENEMY_H


#include"Character.h"
#include"Animation.h"
#include"Rigid_Body.h"
#include"Collision.h"
#include"CollidersManager.h"
#include"Vector.h"


class Enemy : public Character
{

public:
	Enemy(Props* p);

	virtual void Draw();
	virtual void Update(float dt);
	virtual void Clean();



	void AnimationState();

	Collision* m_Collider;
	Animation* m_Anim;
	Rigid_Body* m_Rigs;
	Vector m_LastSave;

};





#endif