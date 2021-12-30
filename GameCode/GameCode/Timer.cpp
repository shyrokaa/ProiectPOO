#include"SDL.h"
#include"Timer.h"


Timer* Timer::s_Instance = nullptr;


void Timer::Tick()
{
	m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (Target_FPS / 1000.0f);

	if (m_DeltaTime > Target_Dtime)
		m_DeltaTime = Target_Dtime;

	m_LastTime = SDL_GetTicks();
}


