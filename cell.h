#ifndef CELL_H
#define CELL_H

#include "object.h"

  class Cell: public Object{

	public:
 	Cell(char);
	bool isDoor();
	bool isPassage();
	bool isTile();
	bool isStair();
	~Cell();
  };

#endif
