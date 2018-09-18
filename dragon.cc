 #include "dragon.h"
#include <fstream>
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
#include "dragonhoard.h"
#include "assassin.h"
#include "berserker.h"
#include "god.h"
using namespace std;

Dragon::Dragon(){
	HP = 150;
	Atk = 20;
	Def = 20;
	Gold = 0;
	DodgeChance = 0;
	setMaxHP(150);
	setHostile(true);
	setDesc("Dragon");
	setChar('D');
}

int Dragon::attack(Shade *shade, int dmg)
{
	shade->addHP(-dmg);
	return dmg;
}


int Dragon::attack(Troll *troll, int dmg)
{
	troll->addHP(-dmg);
	return dmg;
}


int Dragon::attack(Drow *drow, int dmg)
{
	drow->addHP(-dmg);
	return dmg;
}


int Dragon::attack(Vampire *vampire, int dmg)
{
	vampire->addHP(-dmg);
	return dmg;
}


int Dragon::attack(Goblin *goblin, int dmg)
{
	goblin->addHP(-dmg);
	return dmg;
}


int Dragon::attack(Valkyrie *valkyrie, int dmg)
{
	valkyrie->addHP(-dmg);
	return dmg;
}

int Dragon::attack(Assassin *assassin, int dmg)
{
	assassin->addHP(-dmg);
	return dmg;
}

int Dragon::attack(Berserker *berserker, int dmg)
{
	berserker->addHP(-dmg);
	return dmg;
}

int Dragon::attack(God *nomair, int dmg)
{
	nomair->addHP(-dmg);
	return dmg;
}


void Dragon::attackedBy(Player *p)
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
		out << p->getName() << " dealt " << p->attack(this, dmg(p->Atk, Def)) << " damage to " << getDesc() << " (" << HP << " HP). " << endl;
		if (isDead()) {
			p->addGold(dropGold());
			out << "    " << p->getName() << " has slain " << getDesc() << ". " << endl;
		}
	}else {
		cout << p->getName() << " missed its attack. " << endl;
	}
	out.close();
}


Dragon::~Dragon(){}
