#include<iostream>
#include"Texture_Mag.h"
#include"Engine.h"
#include"Camera.h"

using namespace std;

Texture_Mag* Texture_Mag::s_Instance = nullptr;

bool Texture_Mag::Load(string id, string filename) 
{
	SDL_Surface* surface = IMG_Load(filename.c_str());

	if (surface == nullptr)
	{
		cout << "error in surface generation";
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if (texture == nullptr)
	{
		cout << "error in texture generation";
		return false;
	}

	m_TextureMap[id] = texture;

	return true;
}

bool Texture_Mag::Drop(string id)
{
	return true;
}

void Texture_Mag::Clean()
{


}

void Texture_Mag::Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip )
{
	Vector cam = Camera::GetInstance()->GetPosition();

	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect datRect = { x - cam.X, y - cam.Y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &datRect, 0, nullptr, flip);

}

void Texture_Mag::DrawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	Vector cam = Camera::GetInstance()->GetPosition();


	SDL_Rect srcRect = { width*frame, height*(row-1), width, height };
	SDL_Rect datRect = { x - cam.X, y - cam.Y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &datRect, 0, nullptr, flip);

}

void Texture_Mag::DrawTile(string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip )
{


	Vector cam = Camera::GetInstance()->GetPosition();

	SDL_Rect dstRect = { x - cam.X, y - cam.Y, tileSize, tileSize };

	SDL_Rect srcRect = { tileSize * frame , tileSize * (row - 1),tileSize,tileSize };

	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[tilesetID], &srcRect, &dstRect, 0, 0, flip);

}