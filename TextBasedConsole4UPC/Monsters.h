#pragma once
#ifndef __MONSTERS_H__
#define __MONSTERS_H__
#define uint unsigned int 


#include "Entity.h"


class Monster : public Entity {
public:
	String	name;
	String	description;
	String current_place;
	int position_num;//integer used for accessing the rooms
	int damage;
	int life;
	Monster(const char* item_name, const char* item_description, String location, int damage, int life)
	{

		this->name = item_name;
		this->description = item_description;
		this->current_place = location;
		this->damage = damage;
		this->life = life;

	}
public:
	bool Move_Monster(const String& destination);
	bool monster_randmove();
	~Monster();




};

#endif 
