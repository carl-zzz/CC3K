#include <iostream>
#include <fstream>
#include "rh.h"
using namespace std;

RH::RH()
{
	setChar('P');
	setDesc("RH");
}


void RH::useOn(Player *p)
{
	int amount = RESTOREHEALTH;
	if (p->getDesc() == "Drow") amount = amount * 1.5;
	p->addHP(amount);
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << p->getDesc() << " has used an RH potion and restored " << amount << " health. " << endl;
}

RH::~RH(){}
