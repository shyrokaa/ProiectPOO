#ifndef CHARACTER_H
#define CHARACTER_H

#include"G_Object.h"
#include<string>

class Character : public G_Object
{
public:
	Character(){}
	Character(Props* p) : G_Object(p){}

	virtual void Draw() = 0;
	virtual void Update(float d) = 0;
	virtual void Clean() = 0;

protected:
	string m_Name;
};



#endif
