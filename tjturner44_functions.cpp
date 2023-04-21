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
        cin.ignore(255, '\n');
        cout << "File not found." << endl;
        cout << "What is the name of the file with your monster data? (ex: filename.txt)" << endl;
        cout << "FILENAME:  ";
        getline(cin, filename);
        file.open(filename); // Opens file at string filename.
    }

    cout << endl;

    string lineInput; // Simple variable that stores the input from each line of the file as it is read.
    int line = 1; // Tracks which line of the file is being read.

    while(getline(file, lineInput, '#') && !file.eof() && !file.fail()){  // Iterates through each monster in the file.
        if (line>10){ // Resets line to 1 after all of the information for a monster has been added to the array.
            line = 1;
        }
        switch(line){
            case 1:
            monsterCount++; // Adds one monster to the count before all of its information has been added to the array. Also iterates the monster.
            monsterIndex[monsterCount].name = lineInput;
            cout << monsterIndex[monsterCount].name << " has been added." << endl;
            break;

            case 2:
            monsterIndex[monsterCount].description = lineInput;
            break;

            case 3:
            monsterIndex[monsterCount].weight = stod(lineInput);
            break;

            case 4:
            monsterIndex[monsterCount].height = stoi(lineInput);
            break;
            
            case 5:
            monsterIndex[monsterCount].originLocation = lineInput;
            break;

            case 6:
            monsterIndex[monsterCount].dangerLevel = stoi(lineInput);
            break;

            case 7:
            monsterIndex[monsterCount].costWeekly.careHoursNeeded = stod(lineInput);
            break;

            case 8:
            monsterIndex[monsterCount].costWeekly.care = stod(lineInput);
            break;

            case 9:
            monsterIndex[monsterCount].costWeekly.food = stod(lineInput);
            break;

            case 10:
            monsterIndex[monsterCount].costWeekly.supplies = stod(lineInput);
            break;
            }    

        line++; // Increments i to move to the next line of the file.
        
    }
    cout << "\nAll creatures from " << filename << " have been added to the program." << endl;

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
    if (monsterCount > MAX_ZOO_SIZE){
        cout << "The zoo is currently full. No more monsters can be added." << endl;
        return monsterCount; // Returns MAX_ZOO_SIZE (75) if the zoo is full.
    }

    string userInputString; // String stores the users input for each piece of information about the monster.
    int userInputInt; // Int stores the users input for each piece of information about the monster.
    double userInputDouble; // Double stores the users input for each piece of information about the monster.

    monsterCount++; // Adds one monster to the count after all of its information has been added to the array.
    cout << "NAME: ";
    cin.ignore();
    getline(cin, userInputString);
    monsterIndex[monsterCount].name = userInputString;

    cout << "\nDESCRIPTION:  ";
    getline(cin, userInputString);
    monsterIndex[monsterCount].description = userInputString;

    cout << "\nWEIGHT (in pounds):  ";
    cin >> userInputDouble;
    monsterIndex[monsterCount].weight = userInputDouble;
    cin.ignore();

    cout << "\nHEIGHT (in feet):  ";
    cin >> userInputInt;
    monsterIndex[monsterCount].height = userInputInt;
    cin.ignore();

    cout << "\nLAST KNOWN LOCATION:  ";
    getline(cin, userInputString);
    monsterIndex[monsterCount].originLocation = userInputInt;

    cout << "\nDANGER LEVEL (1-5):  ";
    cin >> userInputInt;
    monsterIndex[monsterCount].dangerLevel = userInputInt;
    cin.ignore();

    cout << "\nCARE INFORMATION (per week):";
    cout << "\n\tRequired direct care for monster (in hours) ";
    cin >> userInputDouble;
    monsterIndex[monsterCount].costWeekly.careHoursNeeded = userInputDouble;
    cin.ignore();

    cout << "\n\tCost of care $  ";
    cin >> userInputDouble;
    monsterIndex[monsterCount].costWeekly.care = userInputDouble;
    cin.ignore();

    cout << "\n\tFood cost $  ";
    cin >> userInputDouble;
    monsterIndex[monsterCount].costWeekly.food = userInputDouble;
    cin.ignore();

    cout << "\n\tMedical & grooming cost $ ";
    cin >> userInputDouble;
    monsterIndex[monsterCount].costWeekly.supplies = userInputDouble;
    cin.ignore();
    
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
int removeMonster(int monsterCount, Monster * monsterIndex){
    string userInputString; // String stores the users input for the name of the monster they want to remove.
    cout << "The following is a list of all the monsters in the zoo:" << endl;
    for(int i = 1; i <= monsterCount; i++){
        cout << monsterIndex[i].name << endl;
    }
    cout << "Which monster is leaving the zoo?" << endl;
    cout << "MONSTER NAME:  ";

    getline(cin, userInputString);

    for(int i = 1; i <= monsterCount; i++){
        if (userInputString == monsterIndex[i].name){
            for(int j = i; j < monsterCount; j++){
                monsterIndex[j] = monsterIndex[j+1];
            }
            monsterCount--;
            cout << userInputString << " has been removed from the zoo." << endl;
            return;
        }
    }
    cout << "Sorry, a monster by that name " << userInputString << " could not be found." << endl;
    
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