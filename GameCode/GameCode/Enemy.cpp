#include"Enemy.h"
#include"Texture_Mag.h"
#include"Input.h"
#include"SDL.h"
#include"Camera.h"
#include"Engine.h"
#include"CollidersManager.h"
#include"Collision.h"
#include <ctime>

Enemy::Enemy(Props* p) :Character(p)
{
	m_Collider = new Collision();
	m_Collider->SetBuffer(0, 0, 0, 0);
	
	
	m_Rigs = new Rigid_Body();
	m_Rigs->SetGravity(7.0f);


	m_Anim = new Animation;
	m_Anim->Set(m_TextureID, 1, 6, 200);
}

void Enemy::Draw()
{
	m_Anim->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Flip);
	
	//collision box 

	/*
	Vector cam = Camera::GetInstance()->GetPosition();
	SDL_Rect box = m_Collider->Get();
	box.x -= cam.X;
	box.y -= cam.Y;

	SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(), &box);
	*/
}

void Enemy::Update(float dt)
{
	m_Rigs->RemoveForce();

	m_Rigs->Update(1);
	m_LastSave.X = m_Transform->X;
	m_Transform->X += m_Rigs->GetPosition().X;
	m_Collider->Set(m_Transform->X, m_Transform->Y, 60, 32);



	if (CollidersManager::GetInstance()->MapCollision(m_Collider->Get()))
		m_Transform->X = m_LastSave.X;



	m_Rigs->Update(1);
	m_LastSave.Y = m_Transform->Y;
	m_Transform->Y += m_Rigs->GetPosition().Y;
	m_Collider->Set(m_Transform->X, m_Transform->Y, 60, 32);

	if (CollidersManager::GetInstance()->MapCollision(m_Collider->Get()))
		m_Transform->Y = m_LastSave.Y;
	

	m_Origin->X = m_Transform->X + m_Width / 2;
	m_Origin->Y = m_Transform->Y + m_Height / 2;

	AnimationState();
	m_Anim->Update();
}

void Enemy::Clean()
{
	Texture_Mag::GetInstance()->Clean();
}

void Enemy::AnimationState()
{
	//idle
	m_Anim->Set("slime", 1, 6, 80);

}

