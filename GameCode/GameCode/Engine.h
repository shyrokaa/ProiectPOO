#ifndef ENGINE_H
#define ENGINE_H

#include"SDL.h"
#include"SDL_image.h"
#include"GameMap.h"

#define SCREEN_WIDTH = 960
#define SCREEN_HEIGHT = 640


class Engine
{
public:

	//nu am nevoie de asa ceva
	//Engine();
	// ~Engine();


	static Engine* GetInstance()
	{
		//daca instanta nula - > noua instanta
			return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
	}

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Events();


	inline bool IsRunning() 
	{ 
		return m_IsRunning;
	}
	
	
	inline SDL_Renderer* GetRenderer()
	{
		return m_Renderer;
	}

	inline GameMap* GetMap() 
	{ 
		return m_LevelMap; 
	}

private:

	Engine(){}

	GameMap*  m_LevelMap;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	bool m_IsRunning;
	static Engine* s_Instance;

};

#endif 
