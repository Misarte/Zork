#pragma once
#ifndef __EXITS_H__
#define __EXITS_H__
#include"Entity.h"

class Exits :public Entity {
public:
	String source;
	String destination;
	String direction;
	bool open;
	bool openable;
	void Look()const;

	Exits(const char* source, const char* destination, const char* direction, const char* exit_description, bool open, bool openable) :source(source), destination(destination), direction(direction), open(open), openable(openable)
	{


	}
};
#endif
