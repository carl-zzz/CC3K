#include "god.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "rat.h"
#include "enemy.h"
using namespace std;

God::God()
{
	ORIGINALATK = 0;
	ORIGINALDEF = -101;
	HP = 1;
	Atk = 0;
	Def = -101;
	Gold = 0;
	setDesc("God");
	DodgeChance = 50;
	setMaxHP(1);
}

void God::addHP(int n){}
void God::addDef(int n){}
void God::addAtk(int n){}

int God::attack(Human *human, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Human dies of exhaustion working on Assignment 5. Human took 999 dmg. " << endl;
	human->addHP(-999);
	return 999;
}


int God::attack(Dwarf *dwarf, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Dwarf preemptively digs his own grave and buries himself. took 999 dmg. " << endl;
	dwarf->addHP(-999);
	return 999;
}


int God::attack(Halfling *halfling, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Halfling thought about dodging, then thought better of it. Halfling takes 999 dmg. " << endl;
	halfling->addHP(-999);
	return 999;
}


int God::attack(Elf *elf, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Elf tries to shoot God out of turn. God reflects the arrow. Elf takes 999 dmg. " << endl;
	elf->addHP(-999);
	return 999;
}


int God::attack(Orc *orc, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Orc dies of fright. Orc takes 999 dmg" << endl;
	orc->addHP(-999);
	return 999;
}


int God::attack(Merchant *merchant, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Merchant takes 999 dmg. Merchant calls out to his fellow Merchants for revenge. Good luck with that." << endl;
	merchant->addHP(-999);
	return 999;
}


int God::attack(Rat *rat, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Rat scurries off the board and takes 999 dmg. " << endl;
	rat->addHP(-999);
	return 999;
}


int God::attack(Dragon *dragon, int dmg)
{
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	out << "Dragon aknowledges your superiority. Dragon takes 999 dmg. " << endl;
	dragon->addHP(-999);
	return 999;
}


void God::attackedBy(Enemy *e)
{
	int i = rand() % 100;
	if (i >= this->DodgeChance) {
		int n = rand() % 3;
		ofstream out;
		out.open("action.txt", ios::app);
		out << "    ";
		if(n == 0){
			out << "Having -101 defense is op. (100/(100 + -101)) * atk => -100 * atk. " << e->getDesc() << " attacks you. You gained " << -e->attack(this, dmg(e->Atk, Def)) << " HP" << endl;
		}else if(n == 1){
			out << e->getDesc() << " successfully dealt " << e->attack(this, dmg(e->Atk, Def)) << " damage to " << getName() << ".  Yes you just took negative damage." << endl;
		}else if(n == 2){
			out << getName() << " is a God. You can't take damage." << endl;
			e->attack(this, dmg(e->Atk,Def));
		}else{ 
			out << endl;
		}
		out.close();
	}else{
		ofstream out;
		out.open("action.txt", ios::app);
		out << "    ";
		out << e->getDesc() << " missed its attack. You're god. What did you expect?" << endl;
		out.close();
	}

}

God::~God(){}
