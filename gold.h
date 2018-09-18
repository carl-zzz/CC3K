#ifndef GOLD_H
#define GOLD_H

#include "item.h"

  class Gold: public Item{
  	
	int amt;

	public:
	
	static const int NORM = 2;
	static const int SMALL = 1;
	static const int MHOARD = 4;

	void setAmt(const int);
	int getAmt();
	
  };

#endif
