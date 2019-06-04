#pragma once
#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "String.h"
#include "Vector.h"

class Entity {
public:
	//basic properties
	String name;
	String description;

	//not all variables are used
	int capacity;
	int num_items;
	bool armor;
	int bonus;

	void Look() {};


};


#endif
