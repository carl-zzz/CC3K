#ifndef WA_H
#define WA_H
#include "potion.h"
#include "player.h"

class WA:public Potion {

	static const int WOUNDATK = 5;

	public:

	WA();
	void useOn(Player *);
	~WA();

};

#endif
