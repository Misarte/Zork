#include "stdafx.h"
#include "Exits.h"
#include "World.h"
#include "Character.h"


void Exits::Look()const
{
	printf(">>%s", description.Cstr());
	if (openable)
	{
		if (open)
			printf(">>Door is already opened.\n");
		else
			printf(">>Door is closed.\n");
	}

}