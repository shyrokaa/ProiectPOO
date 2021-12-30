#ifndef COLLIDERSMANAGER_H
#define COLLIDERSMANAGER_H

#include"SDL.h"
#include<vector>
#include"TileLayer.h"
#include"GameMap.h"
#include"Engine.h"


class CollidersManager
{

public:

	bool MapCollision(SDL_Rect a);
	bool CheckCollision(SDL_Rect a, SDL_Rect b);

	static CollidersManager* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new CollidersManager(); }
	
	static CollidersManager* s_Instance;

private:
	
	CollidersManager();

	TileMap m_Collision_Map;
	TileLayer* m_ColLayer;

	

};
#endif



