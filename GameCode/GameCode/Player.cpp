#include"Global.h"

Dot::Dot()
{
	mPosX = 0;
	mPosY = 0;

	mVelX = 0;
	mVelY = 0;
}

void Dot::handleEvent(SDL_Event& e)
{

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}

	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{

		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
	}
}

void Dot::move()
{
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;


	mPosX += mVelX;


	if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH))
	{

		mPosX -= mVelX;
	}

	mPosY += mVelY;

	if ((mPosY < 0) || (mPosY + DOT_HEIGHT > SCREEN_HEIGHT))
	{
		mPosY -= mVelY;
	}
}

void Dot::render(LTexture gDotTexture)
{
	gDotTexture.render(mPosX, mPosY);
}