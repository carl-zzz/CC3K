#include "normalgold.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

NormalGold::NormalGold(int a)
{
	setAmt(a);
}

void NormalGold::useOn(Player *p)
{
	p->addGold(getAmt());
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << p->getName() << " has picked up " << getAmt() << " golds. " << endl;
	out.close();
}

NormalGold::~NormalGold(){}
