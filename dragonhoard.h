#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H
#include "gold.h"
#include "player.h"
#include "dragon.h"

class DragonHoard:public Gold {

	public:
	
	Dragon *dragon;
	DragonHoard(Dragon *);
	void useOn(Player *);
	~DragonHoard();

};

#endif
