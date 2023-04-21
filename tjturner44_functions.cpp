#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "tjturner44_prog4.h"

using namespace std;

/*
Function: loadMonstersFromFile
Parameters: 
    Number of monsters in the monsters array.
    Monster array. 
Description:
    Loads the monster array from a file. The function will return the number of monsters at the zoo after adding all of them from the file.  
*/
int loadMonstersFromFile(int monsterCount, Monster * monsterIndex){
    string filename;
    cout << "What is the name of the file with your monster data? (ex: filename.txt)" << endl;
    cout << "FILENAME:  ";
    getline(cin, filename);

    ifstream file(filename); // Opens file at string filename.

    while(!file.is_open()){
        cin.clear();
        cin.ignore();
        cout << "File not found." << endl;
        cout << "What is the name of the file with your monster data? (ex: filename.txt)" << endl;
        cout << "FILENAME:  ";
        getline(cin, filename);
        ifstream file(filename); // Opens file at string filename.
    }

    cout << endl;
    
    while(monsterCount < MAX_ZOO_SIZE){  // Iterates through each monster in the file.
        for(int i = 1; i <= 10; i++){ // Iterates through the ten data entries per monster.
            string lineInput;
            switch(i){
                case 1:
                getline(file, monsterIndex[monsterCount].name, '#');
                break;

                case 2:
                getline(file, monsterIndex[monsterCount].description, '#');
                break;

                case 3:
                getline(file, lineInput, '#');
                monsterIndex[monsterCount].weight = stoi(lineInput);
                break;

                case 4:
                getline(file, lineInput, '#');
                monsterIndex[monsterCount].height = stoi(lineInput);
                break;
                
                case 5:
                getline(file, monsterIndex[monsterCount].originLocation, '#');
                break;

                case 6:
                getline(file, lineInput, '#');
                monsterIndex[monsterCount].dangerLevel = stoi(lineInput);
                break;

                case 7:
                getline(file, lineInput, '#');
                monsterIndex[monsterCount].costWeekly.careHoursNeeded = stoi(lineInput);
                break;

                case 8:
                getline(file, lineInput, '#');
                monsterIndex[monsterCount].costWeekly.care = stod(lineInput);
                break;

                case 9:
                getline(file, lineInput, '#');
                monsterIndex[monsterCount].costWeekly.food = stod(lineInput);
                break;

                case 10:
                getline(file, lineInput, '#');
                monsterIndex[monsterCount].costWeekly.supplies = stod(lineInput);
            }
            cout << "\n" << monsterIndex[monsterCount].name << "has been added." << endl;
        }
        monsterCount++;
        if(file.eof()){ // This ends the loop at the end of the file.
            cout << "\nAll creatures from " << filename << " have been added to the program." << endl;
            break;
        }
    }

    file.close();
    return monsterCount;

    /*
            What is the name of the file with your monster data? (ex: filename.txt)
            FILENAME:  monsterFile_4-3-2023.txt

            Zombiedog has been added.
            Chucky Chupacabra has been added.
            Celfy has been added.
            Fliggerwit Fletcher has been added.
            Orgodore Borgmore has been added.

            All creatures from monsterFile_4-3-2023.txt have been added to the program.
*/
}


/*
Function: registerMonster
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Takes information from the user  and adds it to the monster array.
*/
int registerMonster(int monsterCount, Monster * monsterIndex){
    return monsterCount;
}

/*
Function: removeMonster
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Removes a monster from the monster array.
*/
void removeMonster(int monsterCount, Monster * monsterIndex){
    
}

/*
Function: printMonsters
Parameters:
    Number of monsters in the monsters array.
    Monster array.
Description:
    Lists all of the monsters in the monster array. Includes all information for each monster.
*/
void printMonsters(int monsterCount, Monster * monsterIndex){
    
}

/*
Function: printCostInfo
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Writes a detailed receipt of each monsters weekly cost, including a total.
*/
void printCostInfo(int monsterCount, Monster * monsterIndex){
    
}

/*
Function: saveMonstersToFile
Parameters: 
    Number of monsters in the monsters array.
    Monster array.
Description:
    Allows the user to save the monster array to a file.
*/
void saveMonstersToFile(int monsterCount, Monster * monsterIndex){
    
}