#ifndef BA_H
#define BA_H
#include "potion.h"
#include "player.h"

class BA:public Potion {

	static const int BOOSTATK = 5;

	public:

	BA();
	void useOn(Player *);
	~BA();

};

#endif
