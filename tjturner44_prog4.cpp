/*
Author: Taylor Turner
Date: 4/18/2023
Purpose: Index and search a monster zoo using dynamic arrays
*/

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "tjturner44_prog4.h"

using namespace std;



int main(){
    Monster* monsterIndex = new Monster[MAX_ZOO_SIZE]; // The array of monsters at the zoo.
    int monsterCount = 0; // The number of monsters in the zoo currently (out of maximum MAX_ZOO_SIZE).
    bool programExit = false; // Tracks when the user wishes to exit the program.
    int menuChoice = 0; // Tracks the current menu choice.

    loadMonstersFromFile(monsterCount, monsterIndex);
    
    // Begin program loop.
    while (programExit != true){
        cout << "What would you like to do?" << endl;
        cout << "\t1.  Register a New Monster" << endl;
        cout << "\t2.  Remove a Monster From Zoo" << endl;
        cout << "\t3.  Print Monsters to Screen" << endl;
        cout << "\t4.  Print Monster Care Cost Data" << endl;
        cout << "\t5.  End Program" << endl;
        cout << "\tEnter 1, 2, 3, 4, or 5." << endl;
        cout << "CHOICE:";
    
        cin >> menuChoice; 

        while (menuChoice < 1 || menuChoice > 5){ // verifies input
            cin.clear();
            cin.ignore(255, '\n');
            cout << "Invalid choice. Please try again." << endl;
            cout << "CHOICE:";
            cin >> menuChoice;
        }

        switch (menuChoice){
            case 1: registerMonster(monsterCount, monsterIndex); // Register a New Monster
                    break;
            case 2: removeMonster(monsterCount, monsterIndex); // Remove a Monster From Zoo
                    break;
            case 3: printMonsters(monsterCount, monsterIndex); // Print Monsters to Screen
                    break;
            case 4: printCostInfo(monsterCount, monsterIndex); // Print Monster Care Cost Data
                    break;
            case 5: programExit = true; // Exit program
                    break;
            default:programExit = true; // Exit program
        }
    }
    // End program loop.

    delete [] monsterIndex;
    return 0;
    
}