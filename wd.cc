#include <iostream>
#include <fstream>
#include "wd.h"
using namespace std;

WD::WD()
{
	setChar('P');
	setDesc("WD");
}


void WD::useOn(Player *p)
{
	int amount = WOUNDDEF;
	if (p->getDesc() == "Drow") amount = amount * 1.5;
	p->addDef(amount);
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << p->getDesc() << " has used an WD potion and decreased " << amount << " defence. " << endl;
	out.close();
}

WD::~WD(){}
