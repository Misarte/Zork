#pragma once
#include "Header.h";
#ifndef __PLAYER_H__
#define __PLAYER_H_
#define uint unsigned int 
#include "Entity.h"

class Character: public Entity
{
public:
	Character();
	/*std::string name, race, sex;

	std::vector<std::string> playerRace;
	int health, totalHealth, maxHealth, heal;
	int level, current_xp, base_xp, xp_to_level, minLevel, maxLevel;*/

	int health_points;
	int player_damage;
	int player_armor;
	int food;
	int water;
	int day;
	int position_num;//integer used for accessing the rooms


	bool Move_Player(const String& destination);
	
	void Pick_Item(const String& item)const;
	void Put_Item_In(const String& something, const String& somewhere)const;
	void Take_Item_From(const String& something, const String& somewhere)const;
	//void Pick_Item_From(const String& something, const String& somewhere)const;//take something from inventory
	void Drop_Item(const String& item)const;
	void PlayerStats();

	//void characterCreation();
};


#endif 