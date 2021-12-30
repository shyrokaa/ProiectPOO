#ifndef CAMERA_H
#define CAMERA_H

#include"SDL.h"
#include"Vector.h"
#include"Point.h"



class Camera
{

public:

	void Update(float dt);
	inline SDL_Rect GetViewBox() { return m_ViewBox; }
	inline Vector GetPosition() { return m_Position; }
	inline void SetTarget(Point* target) { m_Target = target; }
	inline static Camera* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Camera(); }

private:

	Camera() { m_ViewBox = { 0, 0, 960, 640 }; }

	Point* m_Target;
	Vector m_Position;

	SDL_Rect m_ViewBox;
	static Camera* s_Instance;
	

};


#endif