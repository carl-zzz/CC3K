#ifndef WD_H
#define WD_H
#include "potion.h"
#include "player.h"

class WD:public Potion {

	static const int WOUNDDEF = 5;

	public:

	WD();
	void useOn(Player *);
	~WD();

};

#endif
