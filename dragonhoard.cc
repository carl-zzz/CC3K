#include "dragonhoard.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

DragonHoard::DragonHoard(Dragon *dra)
{
	setAmt(6);
	dragon = dra;
}

void DragonHoard::useOn(Player *p)
{
	p->addGold(getAmt());
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << p->getDesc() << " has picked up a dragon hoard(" << getAmt() << " gold). " << endl;
	out.close();
}

DragonHoard::~DragonHoard(){}
