#include<iostream>
#include"Engine.h"
#include"Texture_Mag.h"
#include"Timer.h"
#include"Vector.h"
#include"Input.h"
#include"Wizard.h"
#include"MapParser.h"
#include"Camera.h"
#include"CollidersManager.h"
#include"Collision.h"
#include"Enemy.h"
using namespace std;


//variabile generale

Input* Input::s_Instance = nullptr;
Engine* Engine::s_Instance = nullptr;

Wizard* player_chr = nullptr;

Enemy* enemy1_chr = nullptr;
Enemy* enemy2_chr = nullptr;
Enemy* enemy3_chr = nullptr;
Enemy* enemy4_chr = nullptr;
Enemy* enemy5_chr = nullptr;

bool Engine::Init()
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
	{
		cout << "!!!!ERROR IN INITIALIZATION!!!!";
		return false;
	}

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

	m_Window = SDL_CreateWindow("Flamer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,960, 640 , window_flags);

	if (m_Window == nullptr)
	{
		cout << "!!!!ERROR IN INITIALIZATION!!!!";
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if (m_Renderer == nullptr)
	{
		cout << "!!!!ERROR IN INITIALIZATION!!!!";
		return false;
	}


	if (!MapParser::GetInstance()->Load())
		cout << "failed to load map!" << endl;
	else
		cout << "map was loaded!"<<endl;

	m_LevelMap = MapParser::GetInstance()->GetMaps("map");

	//player animations
	Texture_Mag::GetInstance()->Load("player", "assets/source/idle.png");
	Texture_Mag::GetInstance()->Load("player_move", "assets/source/move.png");
	Texture_Mag::GetInstance()->Load("player_jmp", "assets/source/Jump.png");
	Texture_Mag::GetInstance()->Load("player_atk", "assets/source/Attack.png");
	Texture_Mag::GetInstance()->Load("player_dmg", "assets/source/Damage.png");

	//enemy animations
	Texture_Mag::GetInstance()->Load("slime", "assets/source/Slime_idle.png");
	Texture_Mag::GetInstance()->Load("slime_dead", "assets/source/slime_dead.png");

	//map related
	Texture_Mag::GetInstance()->Load("bg_0", "assets/maps/background/main.png");
	Texture_Mag::GetInstance()->Load("bg", "assets/maps/background/Wasteland_Sky.png");
	Texture_Mag::GetInstance()->Load("bg2", "assets/maps/background/Wasteland_Mountains_2.png");
	Texture_Mag::GetInstance()->Load("bg3", "assets/maps/background/Wasteland_Mountains_1.png");
	Texture_Mag::GetInstance()->Load("bg4", "assets/maps/background/game_over.png");
	Texture_Mag::GetInstance()->Load("bg5", "assets/maps/background/win.png");


	player_chr = new Wizard(new Props("player", 150, 150, 400, 750));

	//enemy related
	enemy1_chr = new Enemy(new Props("slime", 32,32,500, 204));
	enemy2_chr = new Enemy(new Props("slime", 32, 32, 950, 560));
	enemy3_chr = new Enemy(new Props("slime", 32, 32, 1400, 940));
	enemy4_chr = new Enemy(new Props("slime", 32, 32, 2050, 460));
	enemy5_chr = new Enemy(new Props("slime", 32, 32, 2500, 750));

	//Transform tf;
	//tf.Log();

	Camera::GetInstance()->SetTarget(player_chr->GetOrigin());

	m_IsRunning = true;
	return m_IsRunning;

}

bool Engine::Clean()
{
	Texture_Mag::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);

	return 0;
}
void Engine::Quit()
{
	cout << "\t\texited program";
	m_IsRunning = false;

	//cout << player_chr->m_score;
}

void Engine::Update()
{
	float dt = Timer::GetInstance()->GetDeltaTime();
	player_chr->Update(dt);

	//slime 1
	if (player_chr->m_enemy1_killed)
		enemy1_chr->m_Anim->Set("slime_dead", 1, 6, 80);
	else
		enemy1_chr->Update(dt);

	//slime 2
	if (player_chr->m_enemy2_killed)
		enemy2_chr->m_Anim->Set("slime_dead", 1, 6, 80);
	else
		enemy2_chr->Update(dt);

	//slime 3
	if (player_chr->m_enemy3_killed)
		enemy3_chr->m_Anim->Set("slime_dead", 1, 6, 80);
	else
		enemy3_chr->Update(dt);

	//slime 4
	if (player_chr->m_enemy4_killed)
		enemy4_chr->m_Anim->Set("slime_dead", 1, 6, 80);
	else
		enemy4_chr->Update(dt);
	
	//slime 5
	if (player_chr->m_enemy5_killed)
		enemy5_chr->m_Anim->Set("slime_dead", 1, 6, 80);
	else
		enemy5_chr->Update(dt);
	
	m_LevelMap->Update();
	
	Camera::GetInstance()->Update(dt);
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);

	Texture_Mag::GetInstance()->Draw("bg_0", 0, 0, 6400, 3200);
	Texture_Mag::GetInstance()->Draw("bg", 0, 0, 3200, 1600);
	Texture_Mag::GetInstance()->Draw("bg2", 0, 0, 3200, 1600);
	Texture_Mag::GetInstance()->Draw("bg3", 0, 0, 3200, 1600);

	m_LevelMap->Render();

	player_chr->Draw();
	enemy1_chr->Draw();
	enemy2_chr->Draw();
	enemy3_chr->Draw();
	enemy4_chr->Draw();
	enemy5_chr->Draw();
	

	if (player_chr->m_HP <= 0)
	{
		Vector cam = Camera::GetInstance()->GetPosition();
		//cout << "ar trebui sa mori"<<endl;
		Texture_Mag::GetInstance()->Draw("bg4",cam.X,cam.Y, 3200, 1600);
	}

	if (player_chr->m_enemy1_killed && player_chr->m_enemy2_killed && player_chr->m_enemy3_killed&& player_chr->m_enemy4_killed&& player_chr->m_enemy5_killed)
	{
		Vector cam = Camera::GetInstance()->GetPosition();
		Texture_Mag::GetInstance()->Draw("bg5", cam.X, cam.Y, 3200, 1600);
	}

	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	Input::GetInstance()->Listen();
}

