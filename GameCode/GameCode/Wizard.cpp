#include"Wizard.h"
#include"Texture_Mag.h"
#include"Input.h"
#include"SDL.h"
#include"Camera.h"
#include"Engine.h"
#include"CollidersManager.h"
#include"Collision.h"
#include <ctime>


CollidersManager* CollidersManager::s_Instance = nullptr;



Wizard::Wizard(Props* p) :Character(p)
{
	m_HP = 10;
	m_score = 0;

	m_IsGrounded = false;
	m_IsRunning = false;
	m_IsJumping = false;
	m_IsAttacking = false;
	m_enemy1_killed = false;
	m_Jumptime = 0;
	m_JumpForce = jump_f;

	//collider
	m_Collider = new Collision();
	m_Collider->SetBuffer(-60, -40, 0, 0);

	//corp ce respecta legile fizicii
	m_Rigs = new Rigid_Body();
	m_Rigs->SetGravity(7.0f);

	m_Anim = new Animation;
	m_Anim->Set(m_TextureID, 1, 8, 200);
}


void Wizard::Draw()
{
	m_Anim->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Flip);

	/*
	Vector cam = Camera::GetInstance()->GetPosition();
	SDL_Rect box = m_Collider->Get();
	box.x -= cam.X;
	box.y -= cam.Y;

	SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(), &box);
	*/
}


void Wizard::Update(float d)
{
	m_IsRunning = false;
	m_Rigs->RemoveForce();

	//cout << m_LastSave.X << " " << m_LastSave.Y << endl;

	if (Input::GetInstance()->GetAxisKey(HORIZONTAL) == fwd && !m_IsAttacking)
	{
		m_Rigs->ApplyForce_X(fwd * run_f);
		m_Flip = SDL_FLIP_NONE;
		m_IsRunning = true;
	}

	if (Input::GetInstance()->GetAxisKey(HORIZONTAL) == bwd && !m_IsAttacking)
	{
		m_Rigs->ApplyForce_X(bwd * run_f);
		m_Flip = SDL_FLIP_HORIZONTAL;
		m_IsRunning = true;
	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
	{
		m_Rigs->RemoveForce();
		m_IsAttacking = true;
		//m_Collider->Set(m_Transform->X, m_Transform->Y, 70, 70);
	}
	else
		//m_Collider->Set(m_Transform->X, m_Transform->Y, 50, 70);
		m_IsAttacking = false;
	
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W) && !m_IsAttacking)
	{
		m_IsJumping = true;
		m_Rigs->SetGravity(-7.0f);
	}
	else
	{
		m_Rigs->SetGravity(7.0f);
		m_IsJumping = false;
	}

	//slime 1
	if (!m_enemy1_killed) 
	{
		if (m_LastSave.X > 421 && m_LastSave.X < 463 && m_LastSave.Y > 200 && m_LastSave.Y < 238 && !m_IsAttacking)
		{
			m_Rigs->ApplyForce_X(bwd * run_f);
			m_IsDamaged = true;
			m_HP--;
			//cout << "damaged!" << endl;
		}
		
		if (m_LastSave.X > 400 && m_LastSave.X < 470 && m_LastSave.Y > 200 && m_LastSave.Y < 238 && m_IsAttacking)
		{
				m_score++;
				m_enemy1_killed = true;
				cout << "enemy dead" << endl;
		}

	}

	//slime 2
	if (!m_enemy2_killed)
	{
		if (m_LastSave.X > 876 && m_LastSave.X < 910 && m_LastSave.Y > 530 && m_LastSave.Y < 570 && !m_IsAttacking)
		{
			m_Rigs->ApplyForce_X(bwd * run_f);
			m_IsDamaged = true;
			m_HP--;
			//cout << "damaged!" << endl;
		}

		if (m_LastSave.X > 845 && m_LastSave.X < 920 && m_LastSave.Y > 530 && m_LastSave.Y < 570 && m_IsAttacking)
		{
			m_score++;
			m_enemy2_killed = true;
			cout << "enemy dead" << endl;
		}

	}

	//slime 3
	if (!m_enemy3_killed)
	{
		if (m_LastSave.X > 1320 && m_LastSave.X < 1360 && m_LastSave.Y > 920 && m_LastSave.Y < 940 && !m_IsAttacking)
		{
			m_Rigs->ApplyForce_X(bwd * run_f);
			m_IsDamaged = true;
			m_HP--;
			//cout << "damaged!" << endl;
		}

		if (m_LastSave.X > 1305 && m_LastSave.X < 1370 && m_LastSave.Y > 920 && m_LastSave.Y < 940 && m_IsAttacking)
		{
			m_score++;
			m_enemy3_killed = true;
			cout << "enemy dead" << endl;
		}
	}

	//slime 4
	if (!m_enemy4_killed)
	{
		if (m_LastSave.X > 1970 && m_LastSave.X < 2010 && m_LastSave.Y > 430 && m_LastSave.Y < 470 && !m_IsAttacking)
		{
			m_Rigs->ApplyForce_X(bwd * run_f);
			m_IsDamaged = true;
			m_HP--;
			//cout << "damaged!" << endl;
		}

		if (m_LastSave.X > 1955 && m_LastSave.X < 2020 && m_LastSave.Y > 430 && m_LastSave.Y < 470 && m_IsAttacking)
		{
			m_score++;
			m_enemy4_killed = true;
			cout << "enemy dead" << endl;
		}

	}

	//slime 5
	if (!m_enemy5_killed)
	{
		if (m_LastSave.X > 2423 && m_LastSave.X < 2460 && m_LastSave.Y > 720 && m_LastSave.Y < 800 && !m_IsAttacking)
		{
			m_Rigs->ApplyForce_X(bwd * run_f);
			m_IsDamaged = true;
			m_HP--;
			//cout << "damaged!" << endl;
		}

		if (m_LastSave.X > 2400 && m_LastSave.X < 2470 && m_LastSave.Y > 720 && m_LastSave.Y < 800 && m_IsAttacking)
		{
			m_score++;
			m_enemy5_killed = true;
			cout << "enemy dead" << endl;
		}

	}

	m_Rigs->Update(1);
	m_LastSave.X = m_Transform->X;
	m_Transform->X += m_Rigs->GetPosition().X;
	m_Collider->Set(m_Transform->X, m_Transform->Y, 50, 70);

	
	if (CollidersManager::GetInstance()->MapCollision(m_Collider->Get()))
		m_Transform->X = m_LastSave.X;


	m_Rigs->Update(1);
	m_LastSave.Y = m_Transform->Y;
	m_Transform->Y += m_Rigs->GetPosition().Y;
	m_Collider->Set(m_Transform->X, m_Transform->Y, 50, 70);

	if (CollidersManager::GetInstance()->MapCollision(m_Collider->Get()))
	{
		m_IsGrounded = true;
		m_Transform->Y = m_LastSave.Y;
	}
	else
		m_IsGrounded = false;

	m_Origin->X = m_Transform->X + m_Width / 2;
	m_Origin->Y = m_Transform->Y + m_Height / 2;

	AnimationState();
	m_Anim->Update();

}


void Wizard::Clean()
{
	Texture_Mag::GetInstance()->Clean();
}


void Wizard::AnimationState()
{
	//idle
	m_Anim->Set("player", 1, 8, 80);

	//run
	if(m_IsRunning)
		m_Anim->Set("player_move", 1, 8, 200);


	//fly
	if(m_IsJumping)
		m_Anim->Set("player_jmp", 1, 8, 200);


	//attack
	if(m_IsAttacking)
		m_Anim->Set("player_atk", 1, 8, 200);

	//dead
	if (m_IsDamaged)
	{
		m_Anim->Set("player_dmg", 1, 4, 200);
		m_IsDamaged = false;
	
	}
}