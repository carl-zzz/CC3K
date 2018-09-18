#include <iostream>
#include <fstream>
#include "bd.h"
using namespace std;

BD::BD()
{
	setChar('P');
	setDesc("BD");
}


void BD::useOn(Player *p)
{
	int amount = BOOSTDEF;
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	if (p->getDesc() == "Drow") amount = amount * 1.5;
	p->addDef(amount);
	out << p->getDesc() << " has used an BD potion and gained " << amount << " defence. " << endl;
	out.close();
}

BD::~BD(){}
