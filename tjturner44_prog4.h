#ifndef TJTURNER_PROG4_H
#define TJTURNER_PROG4_H


#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ZOO_SIZE = 75; // Global maximum number of monsters the zoo can hold.

struct Cost{
    double careHoursNeeded = 0; // The number of hours it takes to take care of a specific monster per week.
    double care = 0.0; // The cost (per week) of taking care of this monster.
    double food = 0.0; // The cost (per week) of taking care of food.
    double supplies = 0.0; // The cost of materials/supplies (grooming, medical) for this monster for one week
};

struct Monster{
    string name; // The name of the monster.
    string description; // The description of the monster.
    double weight = 0; // The weight of the monster (in pounds)
    int height = 0; // The heigth of the monster (in feet)
    string originLocation; // The location the monster came from before coming to the zoo
    int dangerLevel = 0; // The danger level of the monster (1 to 5 where 1 is not dangerous at all (you can pet it) to 5 being extremely dangerous (it will eat you)
    Cost costWeekly; // The costs associated with the monster's upkeep
};

/*
Function: loadMonstersFromFile
Parameters: 
    Number of monsters in the monsters array.
    Monster array. 
Description:
    Loads the monster array from a file. The function will return the number of monsters at the zoo after adding all of them from the file.  
*/
int loadMonstersFromFile(int, Monster*);

/*
Function: registerMonster
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Takes information from the user  and adds it to the monster array.
*/
int registerMonster(int, Monster*);

/*
Function: removeMonster
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Removes a monster from the monster array.
*/
int removeMonster(int, Monster*);

/*
Function: wrapText
Parameters: 
    String of text to be wrapped.
    Maximum number of characters per line.
Description:
    Wraps text to a new line if the line exceeds the maximum number of characters.
*/
string wrapText(const string&, int);

/*
Function: printMonsters
Parameters:
    Number of monsters in the monsters array.
    Monster array.
Description:
    Lists all of the monsters in the monster array. Includes all information for each monster.
*/
void printMonsters(int, Monster*);

/*
Function: printCostInfo
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Writes a detailed receipt of each monsters weekly cost, including a total.
*/
void printCostInfo(int, Monster*);

/*
Function: saveMonstersToFile
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Allows the user to save the monster array to a file.
*/
void saveMonstersToFile(int, Monster*);

#endif