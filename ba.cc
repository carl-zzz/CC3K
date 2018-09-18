#include <iostream>
#include <fstream>
#include "ba.h"
using namespace std;

BA::BA()
{
	setChar('P');
	setDesc("BA");
}


void BA::useOn(Player *p)
{
	int amount = BOOSTATK;
	if (p->getDesc() == "Drow") amount = amount * 1.5;
	p->addAtk(amount);
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << p->getDesc() << " has used an BA potion and gained " << amount << " attack. " << endl;
	out.close();
}

BA::~BA(){}
