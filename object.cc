#include "object.h"
using namespace std;

Object::Object(){}

string Object::getDesc()
{
	return desc;
}

void Object::setDesc(string s)
{
	desc = s;
}

char Object::getChar()
{
	return c;
}

void Object::setChar(char ch)
{
	c = ch;
}

Object::~Object(){}
