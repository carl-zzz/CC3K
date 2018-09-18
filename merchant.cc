#include "human.h"
#include <fstream>
#include "merchant.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "troll.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"
#include "player.h"
#include "valkyrie.h"
#include "assassin.h"
#include "berserker.h"
#include "god.h"
using namespace std;

Merchant::Merchant()
{
	HP = 30;
	Atk = 70;
	Def = 5;
	Gold = 4;
	DodgeChance = 0;
	setMaxHP(30);
	setHostile(false);
	setDesc("Merchant");
	setChar('M');
}
int Merchant::attack(Shade *shade, int dmg)
{
	shade->addHP(-dmg);
	return dmg;
}


int Merchant::attack(Troll *troll, int dmg)
{
	troll->addHP(-dmg);
	return dmg;
}


int Merchant::attack(Drow *drow, int dmg)
{
	drow->addHP(-dmg);
	return dmg;
}


int Merchant::attack(Vampire *vampire, int dmg)
{
	vampire->addHP(-dmg);
	return dmg;
}


int Merchant::attack(Goblin *goblin, int dmg)
{
	goblin->addHP(-dmg);
	return dmg;
}


int Merchant::attack(Valkyrie *valkyrie, int dmg)
{
	valkyrie->addHP(-dmg);
	return dmg;
}

int Merchant::attack(Assassin *assassin, int dmg)
{
	assassin->addHP(-dmg);
	return dmg;
}

int Merchant::attack(Berserker *berserker, int dmg)
{
	berserker->addHP(-dmg);
	return dmg;
}

int Merchant::attack(God *nomair, int dmg)
{
	nomair->addHP(-dmg);
	return dmg;
}


void Merchant::attackedBy(Player *p)
{
	int i = rand() % 100;
	ofstream out;
	out.open("action.txt", ios::app);
	if(dynamic_cast<God *>(p)){
		p->attack(this, 999);
		return;
	}
	out << "    ";
	if (i >= DodgeChance) {
		setHostile(true);
		out << p->getName() << " dealt " << p->attack(this, dmg(p->Atk, Def)) << " damage to " << getDesc() << " (" << HP << " HP). " << endl;
		if (isDead()) {
			p->addGold(dropGold());
			out << "    " << p->getName() << " has slain " << getDesc() << ". " << endl;
		}
	}else {
		out << p->getName() << " missed its attack. " << endl;
	}
	out.close();
}
Merchant::~Merchant(){}
