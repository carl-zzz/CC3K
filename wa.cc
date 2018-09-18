#include <iostream>
#include <fstream>
#include "wa.h"
using namespace std;

WA::WA()
{
	setChar('P');
	setDesc("WA");
}


void WA::useOn(Player *p)
{
	int amount = WOUNDATK;
	if (p->getDesc() == "Drow") amount = amount * 1.5;
	p->addAtk(-amount);
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << p->getDesc() << " has used an WA potion and decreased " << amount << " attack. " << endl;
	out.close();
}

WA::~WA(){}
