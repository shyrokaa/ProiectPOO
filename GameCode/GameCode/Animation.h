#ifndef ANIMATION_H
#define ANIMATION_H

#include<iostream>
#include"SDL.h"


class Animation
{
public:
	Animation(){}

	void Update();
	void Draw(float x, float y, int sprite_W, int sprite_H, SDL_RendererFlip flip );
	void Set(std::string textureID, int sprite_R, int frame_nr, int speed, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:

	int m_sprite_R, m_sprite_frame, m_speed, m_frames;
	std::string m_TextureID;
	SDL_RendererFlip Flip;


};

#endif 
