#ifndef BD_H
#define BD_H
#include "potion.h"
#include "player.h"

class BD:public Potion {

	static const int BOOSTDEF = 5;

	public:

	BD();
	void useOn(Player *);
	~BD();

};

#endif
