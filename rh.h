#ifndef RH_H
#define RH_H
#include "potion.h"
#include "player.h"

class RH:public Potion {

	static const int RESTOREHEALTH = 10;

	public:

	RH();
	void useOn(Player *);
	~RH();

};

#endif
