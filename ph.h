#ifndef PH_H
#define PH_H
#include "potion.h"
#include "player.h"

class PH:public Potion {

	static const int REDUCEHEALTH = 10;

	public:

	PH();
	void useOn(Player *);
	~PH();

};

#endif
