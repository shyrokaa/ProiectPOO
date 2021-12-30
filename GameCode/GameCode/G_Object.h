#ifndef G_OBJECT_H
#define G_OBJECT_H

#include"SDL.h"
#include"Object.h"
#include"Transform.h"
#include"Point.h"

struct Props
{

	Props(std::string textureID, int width, int height, float x, float y, SDL_RendererFlip flip = SDL_FLIP_NONE)
	{
		Width = width;
		Height = height;
		X = x;
		Y = y;
		Flip = flip;
		TextureID = textureID;
	}

public:

	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;

};

class G_Object : public Object
{

public:
	G_Object(){}
	~G_Object(){}



	G_Object(Props* p)
	{
		m_TextureID = p->TextureID;
		m_Width = p->Width;
		m_Height = p->Height;
		m_Flip = p->Flip;
		m_Transform = new Transform(p->X, p->Y);
		float px = p->X + p->Width / 2;
		float py = p->Y + p->Height / 2;

		m_Origin = new Point(px,py);
	}
	
	inline Point* GetOrigin() { return m_Origin; }

	virtual void Draw() = 0;
	virtual void Update(float d) = 0;
	virtual void Clean() = 0;

protected:

	Transform* m_Transform;
	Point* m_Origin;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
	
};
#endif