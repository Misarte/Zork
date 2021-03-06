// TextBasedConsole4UPC.cpp : Defines the entry point for the console application.
//

//#include "Header.h";
#include "stdafx.h"
#include "Character.h"
#include "World.h"

//void HUD();
void Combat();
void CombatHUD();
//void Navigate();
void CreateMonster();
//void LevelUp();

//initialiation of variables

int monsterHp = 0;
int monsterXp = 0;
int monsterLevel = 0;

std::string monsterNames[] = {"Zombie", "Goblin", "Mutant Shark", "Dwarf", "Witch"};
int currentMonsterNames = 5;
std::string currentMonster = " ";
int counter = 0;

Character character;
World* world = nullptr;

int main()
{
	//character.characterCreation();
	//HUD();
	//Navigate();

	world = new World;


	bool gameloop = true;
	int *character_pos = &world->character->position_num;
	char input_command[50];
	String player_input;
	char* direction;

	String word1;
	String word2;
	String word3;
	String word4;

	world->CreateWorld();
	printf(">>Hello player! Type your name to begin!\n");
	scanf_s("%s", world->character->name);
	printf(">>Okay %s Enjoy! :) .\n", world->character->name);
	printf(">>Instructions given by typing <help> command Instructions: \n");
	printf("\n>> Quit: (quit)\n>> Look at current room: (look)\n>> Navigate: (n/s/e/w/u/d) \n>> Stats:(stats)\n>> Pick/Drop: (pick/drop item_name)\n>> Place in/Remove from: (put item_name in item_name2/ take item_name from item_name2 )\n>> Pick from/Drop from: (put/take item_name from item_location)\n At the Start Type: Look\n\n");

	while (gameloop) {
		while (gameloop)
		{
			
			int aux = 0;
			gets_s(input_command, 50);

			player_input = input_command;

			//break the string into key words
			word1 = player_input.GetWordFromString(1);
			word2 = player_input.GetWordFromString(2);
			word3 = player_input.GetWordFromString(3);
			word4 = player_input.GetWordFromString(4);
			

			CreateMonster();
			//-------------------QUIT---------------------
			if (player_input.stringcomparison("quit")) {
				gameloop = false;
				break;
			}

			//-----------------MOVE-----------------
			else if ( player_input.stringcomparison("n"))
			{
				int temp = rand() % 100 + 1;
				if (world->character->Move_Player("north")) {
					world->character->food -= 5;
					world->character->water -= 5;
					world->Look();
					if (temp >= 50) {
						//Encounter Monster
						CreateMonster();
						std::string tempName = monsterNames[rand() % currentMonsterNames];
						std::cout << "A " << tempName << " is in front of you! Prepare to fight!";
						currentMonster = tempName;
						Sleep(1000);
						Combat();
					}
					break;
				}
			}
			else if (player_input.stringcomparison("s"))
			{
				if (world->character->Move_Player("south"))
				{
					world->character->food -= 5;
					world->character->water -= 5;
					world->Look();
					break;
				}
			}
			else if (player_input.stringcomparison("e"))
			{
				int temp = rand() % 100 + 1;
				if (world->character->Move_Player("east"))
				{
					world->character->food -= 5;
					world->character->water -= 5;
					world->Look();
					if (temp >= 50) {
						//Encounter Monster
						CreateMonster();
						std::string tempName = monsterNames[rand() % currentMonsterNames];
						std::cout << "A " << tempName << " is in front of you! Prepare to fight!";
						currentMonster = tempName;
						Sleep(1000);
						Combat();
					}
					break;
				}
			}
			else if (player_input.stringcomparison("w"))
			{
				if (world->character->Move_Player("west"))
				{
					world->character->food -= 5;
					world->character->water -= 5;
					world->Look();
					break;
				}
			}
			else if (player_input.stringcomparison("u"))
			{
				if (world->character->Move_Player("up"))
				{
					world->character->food -= 5;
					world->character->water -= 5;
					world->Look();
					break;
				}
			}
			else if (player_input.stringcomparison("d"))
			{
				if (world->character->Move_Player("down")) {
					world->character->food -= 5;
					world->character->water -= 5;
					world->Look();
					break;
				}
			}
			//------------------get info about room------------------------
			else if (player_input.stringcomparison("look")) {
				world->Look();
				break;
			}
			

			//-------------------PICK--------------------
			else if ((word1.stringcomparison("pick")))
			{
				world->character->Pick_Item(word2);
				world->Look();
				//system("cls");
				break;
			}

			//------------------PLACE ITEM IN ITEM---------------------
			
			else if ((word1.stringcomparison("put")) && (word3.stringcomparison("in")))
			{

				world->character->Put_Item_In(word2, word4);
				world->Look();
				break;
				//system("cls");
			}
			//------------------REMOVE ITEM FROM ITEM---------------------
			else if ((word1.stringcomparison("take")) && (word3.stringcomparison("from")))
			{

				world->character->Take_Item_From(word2, word4);
				world->Look();
				break;
				//system("cls");
			}
		
			//--------------------DROP-------------------

			else if (word1.stringcomparison("drop"))
			{
				world->character->Drop_Item(word2);
				world->Look();
				break;
			}

			//-----------------STATS-----------------------

			else if (word1.stringcomparison("stats"))
			{
				world->character->PlayerStats();
				
				world->Look();
				//enemy
			}

			//-----------------HELP-----------------(TODO)
			else if (word1.stringcomparison("help"))
			{
				printf("\n>> Quit: (quit)\n>> Look at current room: (look)\n>> Navigate: (n/s/e/w/u/d) \n>> Stats:(stats)\n>> Pick/Drop: (pick/drop item_name)\n>> Place in/Remove from: (put item_name in item_name2/ take item_name from item_name2 )\n>> Pick from/Drop from: (put/take item_name from item_location)\n At the Start Type: Look\n\n");
			}
			
			//INVALID COMMAND
			else if (aux++)
				printf(">>Incorrect Input\n");


		}
	}
	return 0;

	/*system("PAUSE");
    return 0;*/
}
//
//void HUD() {
//	Sleep(500);
//	system("cls");
//	//std::cout << "Name: " << world->character->name << "		Health: " << character.health_points << "\nRace: " << character.race << "\nSex: " << character.sex << "\nLevel : " << character.level << "\nExperience : " << character.current_xp << "\nPoints to NextLevel : " << character.xp_to_level << std::endl;
//	printf("Name: ", world->character->name, "		Health: " , character.health_points, "Type look");
//}
//
void CombatHUD() {
	Sleep(500);
	system("cls");
	printf( "Name: %s",  world->character->name, "		|		Monster Name: %s ", currentMonster, "\nHealth: %d", world->character->health_points, "		|		MonsterHealth: %d ", monsterHp);
	//Navigate();
}

void Combat() {
	CombatHUD();
	int playerAttack;
	int playerDamage = world->character->player_damage;
	int monsterAttack = 4 * monsterLevel / 2;

	if (world->character->health_points >= 1 && monsterHp >= 1) {
		std::cout << "\n\n";
		std::cout << "1. Attack.\n";
		std::cout << "2. Defend.\n";
		std::cout << "3. RUN!!!\n";
		std::cout << "\n";
		std::cin >> playerAttack;

		//Attack
		if (playerAttack == 1) {
			std::cout << "Attacking... You did " << playerDamage << " to the " << currentMonster << std::endl;
			monsterHp -= playerDamage;
			Sleep(500);
			CombatHUD();
			if (monsterHp >= 1) {
				std::cout << "\n";
				std::cout << "The monster is attacking you\n!!!";
				world->character->health_points -= monsterAttack;
				printf("You suffered %d ", monsterAttack, "Hp: %d", world->character->health_points);
				std::cout << "You suffered " << monsterAttack << "Hp:" << world->character->health_points << std::endl;
				if (world->character->health_points <= 0) {
					world->character->health_points = 0;
					system("cls");
					std::cout << "You died! \n You got killed by: " << currentMonster << std::endl;
					Sleep(2000);
					exit(0);
					
				}
			}
			else if (monsterHp <= 0) {
				monsterHp = 0;
				/*if (character.level != character.maxLevel) {
					character.current_xp += monsterXp;
					LevelUp();

				}*/
				std::cout << "\n";
				std::cout << "You defeated " << currentMonster << "You are rewarded with: " << monsterXp << "experience points. Well done! " << std::endl;
				Sleep(1000);
				//HUD();
				world->Look();
			
			}
			Sleep(1000);
			Combat();
		}
		//Defend
		else if (playerAttack == 2) {
			std::cout << "Blocking\n";
			int i = rand() % 100 + 1;
			if (i >= 50) {
				std::cout << "You blocked the incoming attack!\n";
				/*character.heal = character.level * 10 / 2;*/
				std::cout << "You've been healed ";
				world->character->health_points += 10;
				Sleep(1000);
				Combat();
			}
			else {
				std::cout << "You failed to block the incoming attack!\n";
				world->character->health_points -= monsterAttack;
				std::cout << "You've been damaged " << monsterAttack << "points" << "Current Hp:" << world->character->health_points << std::endl;
				Sleep(1000);
				Combat();
			}
		}
		//Run
		else if (playerAttack == 3) {
			std::cout << "Running!!!!!!!!\n";
			int x = rand() % 100 + 1;
			if (x >= 50) {
				std::cout << "You thankfully ran away!\n";
				world->Look();
				//HUD();
			}
			else {
				std::cout << "You didn't ran fast enough!\n";
				std::cout << "Monster Savage Attack!!!\n";
				world->character->health_points -= monsterAttack + 10;
				std::cout << "You've been damaged " << monsterAttack + 10 << "points" << "Current Hp:" << world->character->health_points << std::endl;
				Sleep(1000);
				Combat();
			}
		}
		else {
			std::cout << "Invalid Input\n";
			Sleep(500);
			Combat();
		}
	}
	if (world->character->health_points <= 1) {
		system("cls");
		std::cout << "You died! \n You got killed by: " << currentMonster << std::endl;
		Sleep(2000);
		exit(0);
	}
	if (monsterHp <= 1) {
		/*HUD();
		LevelUp();*/
		world->Look();
		std::cout << "\n";
		std::cout << "You defeated " << currentMonster << "You are rewarded with: " << monsterXp << "experience points. Well done! " << std::endl;
		Sleep(1000);

	}

}
//
//void Navigate() {
//
//	int choice;
//	std::cout << "\n\n";
//	std::cout << "1. Move Forward.\n";
//	std::cout << "2. Chill to Heal.\n";
//	std::cout << "3. Move Backwards.\n";
//	std::cout << "\n";
//
//	std::cin >> choice;
//
//	if (choice == 1) {
//		int temp = rand() % 100 + 1;
//		std::cout << "Moving Forward...\n";
//		if (temp >= 50) {
//			//Encounter Monster
//			CreateMonster();
//			std::string tempName = monsterNames[rand() % currentMonsterNames];
//			std::cout << "A " << tempName << " is in front of you! Prepare to fight!";
//			currentMonster = tempName;
//			Sleep(1000);
//			Combat();
//		}
//		std::cout << "Nothing interesting here...\n";
//		Sleep(1000);
//		HUD();
//
//	}
//	else if (choice == 2) {
//		std::cout << "Setting up a camp for relaxing...\n";
//		if (character.totalHealth <= 99) { //heal
//			character.totalHealth += 10 * character.level;
//		}
//		std::cout << "You healed by resting. Health: " << character.totalHealth << std::endl;
//		Sleep(1000);
//		HUD();
//	}
//	else if (choice == 3) {
//		int temp = rand() % 100 + 1;
//		std::cout << "Moving Backwards...\n";
//		if (temp >= 50) {
//			//Encounter Monster
//			CreateMonster();
//			std::string tempName = monsterNames[rand() % currentMonsterNames];
//			std::cout << "A " << tempName << " is in front of you! Prepare to fight!";
//			currentMonster = tempName;
//			Sleep(1000);
//			Combat();
//		}
//		std::cout << "Nothing interesting here...\n";
//		Sleep(1000);
//		HUD();
//	}
//	else {
//		std::cout << "Invalid Input\n";
//		Sleep(500);
//		Navigate();
//	}
//	
//
//
//}
//
//void LevelUp() {
//	//character.xp += monsterXp;
//	if (character.current_xp >= character.xp_to_level) {
//		character.xp_to_level += floor(character.level) + 25 * pow(2, character.level / 7);
//		character.level++;
//		//character.nextLevel = character.nextLevel * 3 / 2;
//		character.totalHealth = floor(character.totalHealth) + 25 * pow(2, character.level / 8);
//		
//
//		if (character.level >= character.minLevel && character.level <= character.maxLevel) {
//			character.level++;
//
//		}
//		else {
//			character.level = 60;
//		}
//		character.maxHealth = character.totalHealth;
//		std::cout << "Leveling Up!!! You are now level: " << character.level << std::endl;
//		std::cout << "Total Health increased now. Health is: " << character.totalHealth << std::endl;
//		std::cout << "\n";
//		Sleep(1000);
//		LevelUp();
//	}
//
//	Sleep(2000);
//	HUD();
//}
//
void CreateMonster() {
	monsterHp = 30;
	monsterLevel = (rand() % 3);

	if (monsterLevel == 0) {
		monsterLevel = (rand() % 3);
	}

	monsterHp = (rand() % 30) * 2;
	/*if (monsterHp == 0) {
		monsterHp = (rand() % 30) * totalHealth;
	}*/

	monsterXp = monsterHp;
	if (monsterHp == 0) {
		CreateMonster();
	}
	if (monsterLevel == 0) {
		CreateMonster();
	}
}