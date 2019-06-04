#include "stdafx.h"
#include "Items.h"
#include "Character.h"
#include "World.h"
#include <stdio.h>

void Item::Look()
{

	if (current_place.stringcomparison(world->room[world->character->position_num]->name.Cstr()) || current_place.stringcomparison("inventory"))
	{
		printf(">>%s\n", description);

		if (num_items > 0)
			for (int i = 0; i < MAX_ITEMS; i++)
			{
				if (world->item[i]->current_place.stringcomparison(name))
					printf(">>There is a / are %s inside the inventory.\n", world->item[i]->name.Cstr());
			}
	}
}