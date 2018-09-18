#include "player.h"
#include <fstream>
#include "skill.h"
#include <iostream>
using namespace std;
Skill::Skill(const int id):id(id){}

int Skill::AMT[2] = {10, 20};
int Skill::COST[2] = {5, 5};


void Skill::useOn(Player *p){
	if(id == HEAL){
		p->addHP(AMT[HEAL]);
		p->addMP(-COST[HEAL]);
	}
}

bool Skill::useOn(Player *p, Enemy *e){
	if(e == NULL){return false;}
	if(id == DIVSTRIKE){
		e->addHP(-AMT[DIVSTRIKE]);
		p->addMP(-COST[DIVSTRIKE]);
		p->addHP(AMT[DIVSTRIKE] / 2);
		ofstream out;
		out.open("action.txt", ios::app);
		out << "    ";
		out << p->getName() << " used 'Divine Strike' on " << e->getDesc() << "." << endl;
		out << "    ";
		out << p->getName() << " dealt " << AMT[DIVSTRIKE] << " dmg to " <<	 e->getDesc() << " and gained " << AMT[DIVSTRIKE] / 2 << " health." << endl;
		out.close();
		return true;
	}
	return false;
}

bool Skill::isTargetted(){
	return (id == DIVSTRIKE);
}

Skill::~Skill(){}

