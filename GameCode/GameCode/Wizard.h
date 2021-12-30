#ifndef PLAYER_H
#define PLAYER_H

#include"Character.h"
#include"Animation.h"
#include"Rigid_Body.h"
#include"Collision.h"
#include"CollidersManager.h"
#include"Vector.h"



#define jump_f 10.0f
#define run_f 7.0f

#define jmp_t 10.0f
#define atk_t 10.0f

class Wizard : public Character
{
public:

	Wizard(Props* p);

	virtual void Draw();
	virtual void Update(float d);
	virtual void Clean();



	void AnimationState();

	bool m_IsJumping;
	bool m_IsGrounded;
	bool m_IsAttacking;
	bool m_IsRunning;
	bool m_IsDead;
	bool m_IsDamaged;

	bool m_enemy1_killed;
	bool m_enemy2_killed;
	bool m_enemy3_killed;
	bool m_enemy4_killed;
	bool m_enemy5_killed;


	float m_Jumptime;
	float m_JumpForce;
	float m_AttackTime;

	int m_HP;
	int m_score;

	Collision* m_Collider;
	Animation* m_Anim;
	Rigid_Body* m_Rigs;
	Vector m_LastSave;

};

#endif
