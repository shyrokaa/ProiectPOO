#ifndef TEXTURE_MAG_H
#define TEXTUER_MAG_H

#include<map>
#include<string>

#include"SDL.h"
using namespace std;

class Texture_Mag
{
public:
	static Texture_Mag* GetInstance(){return s_Instance = (s_Instance != nullptr) ? s_Instance : new Texture_Mag();}

	bool Load(string id, string filename);
	bool Drop(string id);
	void Clean();

	//basic imagini

	void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);


	//animatii

	void DrawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);


	//tile-map biz

	void DrawTile(string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:

	Texture_Mag() {}
	map< string , SDL_Texture* > m_TextureMap;
	static Texture_Mag* s_Instance;

};

#endif