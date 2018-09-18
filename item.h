#ifndef ITEM_H
#define ITEM_H

#include "object.h"
#include "player.h"

  class Item: public Object{
  	
	public:
	
	Item();
	virtual void useOn(Player *) = 0;
	~Item();
  };

#endif
