#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
using namespace std;

class Vector
{
public:
	float X, Y;

	Vector(float x = 0,float y = 0):X(x),Y(y) {}

//private:

	//override adunare vectoriala
	inline Vector operator+(const Vector V) const
	{
		return Vector(X + V.X, Y + V.Y);

	}

	//override scadere vectoriala
	inline Vector operator-(const Vector V) const
	{
		return Vector(X - V.X, Y - V.Y);
	}

	inline Vector operator*(const float scalar) const
	{
		return Vector(X*scalar, Y*scalar);
	}

	void Log(string msg = "")
	{
		cout <<"\t"<< msg << "\n\tX = " << X << "\n\tY = " << Y << endl;

	}
};

#endif