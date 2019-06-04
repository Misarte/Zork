#pragma once
#ifndef __WORLD_H__
#define __WORLD_H__

#define MAX_ITEMS 10
#define MAX_MONSTERS 4
#define MAX_ROOMS 30
#define MAX_EXITS 30

#include <string.h>
#include <iostream>

#include "String.h"
#include "Vector.h"
#include "Rooms.h"
#include "Exits.h"
#include "Items.h"
#include "Monsters.h"

class Character;

class World {
public:
	World();
	void CreateWorld();
	void Look()const;
	~World();
public:
	Character* character;
	Vector <Room*> room;
	Vector <Exits*> exit;
	Vector <Item*> item;
	Vector <Monster*> monster;

};

extern World* world;

#endif

