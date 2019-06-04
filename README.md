# Zork
C++ simple console game

Tha game consists of 6 Classes and 2 more header files. 

There are 8 possible navigation areas-rooms: Port,
Ancient Ruins, Forrest, River, Field, House, Storage Room, Abandoned Factory. 

There are 6 items in various rooms: backpack, sword, key,tools kit, case, gun.

The player can: 

look at a room receiving a description of where he is ---> typing "look", 

quit the game ---> typing "quit", 

see the instructions  ---> typing "help",

see his statistics  ---> typing "stats", 

navigate through the rooms  ---> typing "n/w/e/s", 

encounter monsters which he can 1.Attack, 2.Defend, 3.Run away from,

pick up items  ---> typing "pick" space and the item's name, 

drop items  ---> typing "drop" space and the item's name, 

place items in other items  ---> typing "put" space the item's name "in" the second item's name, 

take items out of other items ---> typing "put" space the item's name "in" the second item's name(only with specific commands).

Extra feature:
My extra feature is Combat with monsters (Zombie, Goblin, Mutant Shark, Dwarf, Witch). When the player goes north or east a random variable decides if the player will encounter a monster. If the player meets a monster he has 3 options: 1.Attack, 2.Defend, 3.RUN!
Attacking damages the monster but the plaer also receives damage. If damage is big enough the player dies and the game exits. Accordingly, defending gives health points to player, but randomly it is possible that the player fails to defend. In a same manner, running away can fail or succeed, placing player back into Look() method.

