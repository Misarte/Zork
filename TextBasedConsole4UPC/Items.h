#pragma once
#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "Entity.h"


class Item :public Entity
{
public:

	String current_place;
	enum ItemType
	{
		ITEM,
		WEAPON,
		ARMOUR
	};

	Item(const char* item_name, const char* item_description, String location, int number, bool isarmor, int num_bonus)
	{

		name = item_name;
		description = item_description;
		current_place = location;
		num_items = number;
		armor = isarmor;
		bonus = num_bonus;
	}

	void Look();
};

#endif
