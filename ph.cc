#include <iostream>
#include <fstream>
#include "ph.h"
using namespace std;

PH::PH()
{
	setChar('P');
	setDesc("PH");
}


void PH::useOn(Player *p)
{
	int amount = REDUCEHEALTH;
	if (p->getDesc() == "Drow") amount = 1.5 * amount;
	if (p->HP - amount <= 0) amount = p->HP - 1; 	
	p->addHP(-amount);
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << p->getDesc() << " has used an PH potion and reduced " << amount << " health. " << endl;
	out.close();
}

PH::~PH(){}
