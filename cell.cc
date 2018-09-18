#include "cell.h"
using namespace std;

Cell::Cell(char ch)
{
	setChar(ch);
}

bool Cell::isDoor()
{
	if (getChar() == '+')
		return true;
	else return false;
}

bool Cell::isPassage()
{
	if (getChar() == '#')
		return true;
	else return false;
}

bool Cell::isTile()
{
	if (getChar() == '.')
		return true;
	else return false;
}

bool Cell::isStair()
{
	if (getChar() == '\\')
		return true;
	else return false;
}

Cell::~Cell(){}
