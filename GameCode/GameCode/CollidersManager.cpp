#include"CollidersManager.h"
#include"Engine.h"
#include<iostream>

CollidersManager::CollidersManager()
{
	m_ColLayer = (TileLayer*)Engine::GetInstance()->GetMap()->GetMapLayers().back();

	m_Collision_Map = m_ColLayer->GetTileMap();

}

bool CollidersManager::CheckCollision(SDL_Rect a, SDL_Rect b)
{

	bool X_overlap = (a.x < b.x + b.w) && (a.x + a.w > b.x);
	bool Y_overlap = (a.y < b.y + b.h) && (a.y + a.h > b.y);

	return(X_overlap && Y_overlap);

}

bool CollidersManager::MapCollision(SDL_Rect a)
{

	int tileSize = 32;

	int RowCount = 100;
	int ColCount = 100;

	int left_tile = a.x / tileSize;
	int right_tile = (a.x + a.w) / tileSize;

	int top_tile = a.y / tileSize;
	int bottom_tile = (a.y + a.h) / tileSize;


	if (left_tile < 0)
		right_tile = 0;

	if (right_tile > ColCount)
		right_tile = ColCount;



	if (top_tile < 0)
		top_tile = 0;

	if (bottom_tile > RowCount)
		bottom_tile = RowCount;

	//std::cout << left_tile <<" "<< right_tile <<" "<< top_tile<<" "<< bottom_tile;


	for (int i = left_tile; i < right_tile; ++i)
	{
		for (int j = top_tile; j < bottom_tile; ++j)
		{
			if (m_Collision_Map[j][i] > 0)
				return true;
		}
	}
	return false;
}

