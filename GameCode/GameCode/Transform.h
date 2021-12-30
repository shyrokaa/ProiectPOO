#ifndef TRANSFOR_H
#define TRANSFORM_H
#include"Vector.h"

class Transform
{
public:

	float X, Y;

	Transform(float x = 0, float y = 0) :X(x), Y(y) {}

	void Log(string msg = "")
	{
		cout << "\t" << msg << "\n\tX = " << X << "\n\tY = " << Y << endl;
	}

	inline void TranslateX(float x)
	{
		X += x;
	}
	
	inline void TranslateY(float y) 
	{
		Y += y;
	}
	
	inline void Translate(Vector v) 
	{
		X += v.X;
		Y += v.Y;
	}

};

#endif
