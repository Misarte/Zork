#include "stdafx.h"
#include "Character.h"
#include "World.h"


Character::Character()
{
	//name = " ";
	//race = " ";
	//sex = " ";
	//playerRace = { "Human", "Goblin", "Elf", "Dwarf", "King" };
	//level = 0, health = 0, totalHealth = 0, maxHealth = 0, heal = 0;

	//level = 1, current_xp = 0, base_xp = 83, xp_to_level = base_xp, minLevel = 1, maxLevel = 60;
	name = "name";
	position_num = 0;
	health_points = 20;
	player_damage = 3;
	player_armor = 2;
	food = 50;
	water = 50;
}

//void Character::characterCreation() {
//	int counter = 0;
//
//
//
//
//					//basic character creation
//	std::cout << "Hello player! Welcome to the adventure! Enter the Character's Name:";
//	std::cin >> name;
//
//	std::cout << "Enter the Character's Race\n";
//	std::cout << "Human.\n";
//	std::cout << "Goblin.\n";
//	std::cout << "Elf.\n";
//	std::cout << "Dwarf.\n";
//	std::cout << "King.\n";
//	std::cout << "Type below your race: \n\n";
//	std::cin >> race;
//	std::for_each(race.begin(), race.end(), [](char & c) {
//		c = ::tolower(c);
//	});
//
//	for (int i = 0; i < sizeof(playerRace); i++) {
//		if (race == "Human") {
//			health = 80;
//			break;
//		}
//		if (race == "Goblin") {
//			health = 120;
//			break;
//		}
//		if (race == "Elf") {
//			health = 90;
//			break;
//		}
//		if (race == "Dwarf") {
//			health = 100;
//			break;
//		}
//		if (race == "King") {
//			health = 75;
//			break;
//		}
//		else {
//			health = 100;
//			break;
//		}
//	}
//
//	std::cout << "\n";
//	std::cout << "Enter the Character's Sex:";
//	std::cin >> sex;
//
//	system("cls");
//	//console animation
//	for (int i = 0; i <= counter; i++) {
//		if (i == 0) {
//			std::cout << "Creating Character.\n";
//		}
//		if (i == 1) {
//			std::cout << "Creating Character.\n";
//		}
//		if (i == 2) {
//			std::cout << "Creating Character...\n";
//			break;
//		}
//		Sleep(400);
//		system("cls");
//		counter++;
//	}
//
//	name[0] = toupper(name[0]);
//	race[0] = toupper(race[0]);
//	sex[0] = toupper(sex[0]);
//
//	totalHealth = health;
//	maxHealth = totalHealth;
//
//}

bool Character::Move_Player(const String& destination)
{

	for (int i = 0; i < MAX_EXITS; i++)
	{
		printf("Moving Player...\n");
		Sleep(1000);
		if (world->exit[i]->direction.stringcomparison(destination.Cstr()) && world->exit[i]->source.stringcomparison(world->room[position_num]->name.Cstr()))
		{
			if ((world->exit[i]->openable) && (world->exit[i]->open == false))
			{
				printf("The door is closed.\n");
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
	printf("Invalid Input. You can't do that.\n");
	return false;
}

void Character::Pick_Item(const String& item_name)const
{
	int i;

	for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->name.stringcomparison(item_name.Cstr()) && world->item[i]->current_place.stringcomparison(world->room[position_num]->name.Cstr()))
		{

			printf("You picked the %s.\n", world->item[i]->name.Cstr());
			world->item[i]->current_place = "Inventory";
			break;
		}
	}
	if (i == MAX_ITEMS)
		printf("There's nothing like that here.\n");
}

void Character::Put_Item_In(const String& item_name, const String& item_name2)const
{
	int i;

	for (i = 0; i < MAX_ITEMS; i++)
	{
		world->item[i]->name = item_name;
		printf("You picked the %s.\n", world->item[i]->name.Cstr());
		world->item[i]->current_place = item_name2;
		printf("and placed it in %s.\n", world->item[i]->current_place.Cstr());
		break;
	}
	if (i == MAX_ITEMS)
		printf("There's nothing like that here.\n");
}

void Character::Take_Item_From(const String& item_name, const String& item_name2)const
{
	int i;

	for (i = 0; i < MAX_ITEMS; i++)
	{
		world->item[i]->name = item_name;
		printf("You took the %s.\n", world->item[i]->name.Cstr());
		world->item[i]->current_place = item_name2;
		printf("out of the %s.\n", world->item[i]->current_place.Cstr());
		break;
	}
	if (i == MAX_ITEMS)
		printf("There's nothing like that here.\n");
}

void Character::Drop_Item(const String& item_name)const
{
	int i;
	for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->current_place.stringcomparison("Inventory") && world->item[i]->name.stringcomparison(item_name.Cstr()))
		{
			world->item[i]->current_place = world->room[position_num]->name.Cstr();
			printf("You dropped the %s.\n", world->item[i]->name.Cstr());
			break;
		}
		if (MAX_ITEMS == i)
			printf("you don't have a %s in your inventory.\n", item_name.Cstr());
	}
}

void Character::PlayerStats()
{
	printf(">> %s , you have %d health points left\n", name.buffer, health_points);
	printf(">> %s Attack: %d\n>> %s Equipment:%d\n", name.buffer, player_damage, name.buffer, player_armor); // it crashes i don't know why
	printf(">> You have %d / 100 food and %d / 100 water currently\n", food, water);
}
