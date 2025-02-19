#ifndef INPUT_H
#define INPUT_H

#include"SDL.H"

enum Axis { HORIZONTAL, VERTICAL };

class Input
{
public:

	static Input* GetInstance()
	{
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Input();

	}

	void Listen();
	bool GetKeyDown(SDL_Scancode key);

	int GetAxisKey(Axis axis);

private:
	Input();

	void KeyUP();
	void KeyDown();

	const Uint8* m_Keystates;
	static Input* s_Instance;



};




#endif
