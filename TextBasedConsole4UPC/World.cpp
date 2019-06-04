#include "stdafx.h"
#include "World.h"
#include "Character.h"


World::World()
{
	character = new Character;

}

World::~World()
{
	delete character; 
}

void World::Look()const {

	printf("%s%s", room[character->position_num]->name.Cstr(), room[character->position_num]->description.Cstr());

}

void World::CreateWorld()
{

	//----------ITEMS--------------
	item.PushBack(new Item("backpack", "A big weapon that seems to be useful to deal with some problems.\n", "Port", 6, false, 3));
	item.PushBack(new Item("sword", "A big weapon that seems to be useful to deal with danger.\n", "Ancient Ruins", 1, true, 5));
	item.PushBack(new Item("key", "Better keep it safe, keys are commonly useful.\n", "House", 1, false, 3));
	item.PushBack(new Item("tools kit", "a set of tools that a good electrician man would have.\n", "Abandoned Factory", 3, false, 0));
	item.PushBack(new Item("case", "this will protect your head.\n", "Forrest", 2, false, 2));
	item.PushBack(new Item("gun", "this will protect your head.\n", "Locked Room", 1, true, 5));

	//------------ROOMS---------------

	room.PushBack(new Room("Port", " : You are in the beggining of your adventure! In front you can see a long road towards west and e fence hides the view on the north. Mutant Sharks are swimming in the sea. A backpack is laying on the floor(type: w or pick)\n.\n"));
	room.PushBack(new Room("Ancient Ruins", " : You are at some ancient ruins. Looks spooky here. Quickly pick up the sword before a monster appears. North there is a bridge and west you see some trees.(type: n/w/e).\n"));
	room.PushBack(new Room("Forrest", " : You are at a forrest. Good place to eat some fruits and gain energy. There is a case on the ground (type: n/e or pick).\n"));
	room.PushBack(new Room("River", ": You are in front of a river, the only place of the game with drinkable water, there is no exit except from going back(type: south)\n"));
	room.PushBack(new Room("Field", " : You are at an empty field. There is nothing interesting here...(type: n/w/e/s)\n"));
	room.PushBack(new Room("House", " : You are in a house. You can see a ladder going up. First pick up the key.(type: s/u)\n "));
	room.PushBack(new Room("Locked Room", " : You are in a storage room and u see a gun on the ground. (Type: d or pick)\n"));
	room.PushBack(new Room("Un-locked Room", " : You are in a storage room and u see a gun on the ground. (Type: d)\n"));
	room.PushBack(new Room("Abandoned Factory", " : You are in an abandoned factory. You hear zombie sounds, but you can see a lot of tools around that could be useful.(type: w/s or pick)\n"));


	//--------------------EXITS-------------------------
	exit.PushBack(new Exits("Port", "Abandoned Factory", "north", "you only see a huge abandoned building but there is a fence", true, false));
	exit.PushBack(new Exits("Port", "Ancient Ruins", "west", "you see some ruins in that direction", true, false));
	exit.PushBack(new Exits("Ancient Ruins", "Field", "north", "you see a forrest", true, false));
	exit.PushBack(new Exits("Ancient Ruins", "Forrest", "west", "you see a long path", true, false));
	exit.PushBack(new Exits("Ancient Ruins", "Port", "east", "on the east is the port where you came from", true, false));
	exit.PushBack(new Exits("Forrest", "River", "north", "you can see a long river", true, false));
	exit.PushBack(new Exits("Forrest", "Ancient Ruins", "east", "the skulls and ruins in the east", true, true));
	exit.PushBack(new Exits("River", "Forrest", "south", "behind you is the food", true, false));
	exit.PushBack(new Exits("Field", "House", "north", "you can see a house in your north", true, false));
	exit.PushBack(new Exits("Field", "Forrest", "west", "the trees on your west", true, false));
	exit.PushBack(new Exits("Field", "Abandoned Factory", "east", "you see an old factory", true, false));
	exit.PushBack(new Exits("Field", "Ancient Ruins", "south", "you see an old factory", true, false));/*
	exit.PushBack(new Exits("House", "Abandoned Factory", "east", "", true, false));*/
	exit.PushBack(new Exits("House", "Field", "south", "you see the field behind you", true, false));
	exit.PushBack(new Exits("House", "Locked Room", "up", "you can see a storage room", true, false));
	exit.PushBack(new Exits("Locked Room", "House", "down", "you see a deep forest in the end of the path", false, true));
	exit.PushBack(new Exits("Un-locked Room", "House", "down", "you can see a ladder going down and a gun", true, true));/*
	exit.PushBack(new Exits("Abandoned Factory", "House", "west", "you see a deep forest at the end of the path", true, false));*/
	exit.PushBack(new Exits("Abandoned Factory", "Port", "south", "you see the port at the end of the path", true, false));


	monster.PushBack(new Monster("Zombie", "A zombie that eats brains", "Abandonded Factory", 5, 8));
	monster.PushBack(new Monster("Dragon", "A dragon that spits fire", "Ancient Ruins", 3, 6));
	monster.PushBack(new Monster("Mutant Shark", "A big shark with legs that can walk", "Port", 10, 50));

}
