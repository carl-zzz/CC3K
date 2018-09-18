#include "enemy.h"
#include "player.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "assassin.h"
#include "berserker.h"
#include "god.h"
using namespace std;

Enemy::Enemy(){}

int Enemy::dropGold()
{
	return Gold;
}


bool Enemy::isHostile()
{
	return hostile;
}


void Enemy::setHostile(bool b)
{
	hostile = b;
}

Enemy::~Enemy(){}
