#include"Animation.h"
#include"Texture_Mag.h"

void Animation::Update()
{
	m_sprite_frame = (SDL_GetTicks() / m_speed) % m_frames;
}


void Animation::Draw(float x, float y, int sprite_W, int sprite_H,SDL_RendererFlip flip )
{
	Texture_Mag::GetInstance()->DrawFrame(m_TextureID, x, y, sprite_W, sprite_H, m_sprite_R, m_sprite_frame);
}

void Animation::Set(std::string textureID, int sprite_R, int frame_nr, int speed, SDL_RendererFlip flip )
{

	m_TextureID = textureID;
	m_sprite_R = sprite_R;
	m_frames = frame_nr;
	m_speed = speed;
	Flip = flip;

}