#ifndef NORMALGOLD_H
#define NORMALGOLD_H
#include "gold.h"
#include "player.h"

class NormalGold:public Gold {

	public:

	NormalGold(int);
	void useOn(Player *);
	~NormalGold();

};

#endif
