#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

  class Object{
	
	char c;
	std::string desc;

	public:
	
	Object();
	std::string getDesc();
	void setChar(char);
	void setDesc(std::string);
	char getChar();
	virtual ~Object();
  };

#endif
