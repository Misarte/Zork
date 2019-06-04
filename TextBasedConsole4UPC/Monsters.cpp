#include "stdafx.h"
#include "Monsters.h"

#include "World.h"
#include<time.h>
#include <stdlib.h>  




Monster::~Monster()
{}
bool Monster::Move_Monster(const String& destination)
{
	for (int i = 0; i < MAX_EXITS; i++)
	{

		if (world->exit[i]->direction.stringcomparison(destination.Cstr()) && world->exit[i]->source.stringcomparison(world->room[position_num]->name.Cstr()))
		{
			if ((world->exit[i]->openable) && (world->exit[i]->open == false))
			{
				printf("Door is closed.\n");
				return false;
			}

			if (world->exit[i]->destination.Empty())
			{
				printf("%s", world->exit[i]->description.Cstr());
				return false;
			}


			for (int j = 0; j < MAX_ROOMS; j++)
				if (world->room[j]->name.stringcomparison(world->exit[i]->destination.Cstr()))
				{

					position_num = j;
					return true;
				}
		}
	}
	printf("You can't do that.\n");
	return false;
}

bool Monster::monster_randmove()
{
	int var;
	srand(time(NULL));
	var = rand() % 4;


	switch (var)
	{

	case 0:
		if (Move_Monster("north"))
		{
			Move_Monster("north");
			return true;
		}
		break;
	case 1:
		if (Move_Monster("south"))
		{
			Move_Monster("south");
			return true;
		}
		break;
	case 2:
		if (Move_Monster("east"))
		{
			Move_Monster("east");
			return true;
		}
		break;
	case 3:
		if (Move_Monster("west"))
		{
			Move_Monster("west");
			return true;
		}
		break;
	}
	return false;
}

