#include "player.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "rat.h"
#include "skill.h"
using namespace std;

Player::Player()
{
	setChar('@');
}


int Player::getScore(){
	return 2 * getGold();
}

void Player::preTurn(){}

void Player::learn(Skill *s){
	if(s1 == NULL){
		s1 = s;
	}else if(s2 == NULL){
		s2 = s;
	}
}

void Player::addMP(int m){	
	MP += m;
	if(MP > maxMP){MP = maxMP;}
}

void Player::setName(string name)
{
	Name = name;
}


string Player::getName()
{
	return Name;
}


void Player::postTurn()
{

}

int Player::getGold()
{
	return Gold;
}

void Player::addGold(const int n)
{
	Gold = Gold + n;
}

void Player::reset()
{
	Atk = ORIGINALATK;
	Def = ORIGINALDEF;
}

Player::~Player(){}
