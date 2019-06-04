#pragma once
#ifndef __ROOMS_H__
#define __ROOMS_H__
#include"Entity.h"

class Room :public Entity {
public:
	String name;
	String description;


	Room(const char* room_name, const char* room_description)
	{
		name = room_name;
		description = room_description;
	}
};

#endif
