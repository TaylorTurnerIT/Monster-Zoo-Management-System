#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
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

    while(!file.is_open()){ // Checks if the file is open. If not, it will ask for a new filename.
        cin.clear();
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

        line++; // Increments to move to the next line of the file.
        
    }
    cout << "\nAll creatures from " << filename << " have been added to the program." << endl;

    file.close();
    return monsterCount;
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
        cout << "\n\nThe zoo is currently full. No more monsters can be added." << endl;
        return monsterCount; // Returns MAX_ZOO_SIZE (75) if the zoo is full.
    }

    string userInputString; // String stores the users input for each piece of information about the monster.
    int userInputInt; // Int stores the users input for each piece of information about the monster.
    double userInputDouble; // Double stores the users input for each piece of information about the monster.

    monsterCount++; // Adds one monster to the count after all of its information has been added to the array.
    cout << "\n\nNAME: ";
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
    cin.ignore();
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

    cout << "\n\n" << monsterIndex[monsterCount].name << " has been added." << endl;
    
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
    cout << "\n\nThe following is a list of all the monsters in the zoo:" << endl;
    for(int i = 1; i <= monsterCount; i++){ // Iterates through the monster array and prints the name of each monster.
        cout << monsterIndex[i].name << endl;
    }
    cout << "Which monster is leaving the zoo?" << endl;
    cout << "MONSTER NAME:  ";
    cin.ignore();
    getline(cin, userInputString);

    for(int i = 1; i <= monsterCount; i++){ // Iterates through the monster array.
        if (userInputString == monsterIndex[i].name){ // If the name of the monster matches the name of the monster in the array, the monster is removed.
            for(int j = i; j <= monsterCount; j++){ // Iterates through the monster array, starting at the monster that is being removed.
                monsterIndex[j] = monsterIndex[j+1]; // Moves the next monster in the array to the current position in the array.
            }
            monsterCount--;
            cout << userInputString << " has been removed from the zoo." << endl << endl << endl;
            return monsterCount; // Returns the new number of monsters in the array.
        }
    }
    cout << "Sorry, a monster by that name " << userInputString << " could not be found." << endl; // If the name of the monster does not match the name of any monster in the array, the user is notified.
    return monsterCount; // Returns the original number of monsters in the array.
}



/*
Function: wrapText
Parameters: 
    String of text to be wrapped.
    Maximum number of characters per line.
Description:
    Wraps text to a new line if the line exceeds the maximum number of characters.
*/
string wrapText(const string& text, int maxCharsPerLine)
{
    stringstream ss(text); // String stream allows the string to be split into words.
    string line, word; // Line stores the current line of text. Word stores the current word being added to the line.
    string wrappedText; // String that will be returned.

    while (getline(ss, word, ' ')) // Iterates through the string stream, splitting the string into words.
    {
        if (line.length() + word.length() > maxCharsPerLine) // If the line exceeds the maximum number of characters, the line is added to the wrapped text and the line is reset.
        {
            wrappedText += line + "\n\t"; // Adds the line to the wrapped text and adds a tab to the beginning of the next line.
            line = "";
        }
        line += word + ' ';
    }

    wrappedText += line;
    return wrappedText;
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
    if (monsterCount == 0){ // If there are no monsters in the array, the user is notified.
        cout << "\n\nTHERE ARE NO MONSTERS AT YOUR ZOO!" << endl;
        return;
    }
    for (int i = 1; i <= monsterCount; i++){ // Iterates through the monster array and prints all information for each monster.
        string description = wrapText(monsterIndex[i].description, 60); // Wraps the description of the monster to a new line if the line exceeds 72 characters.
        cout << "\n\n------------------------------------------------------------------------";
        cout << "\n**MONSTER " << i << "**" << endl;
        cout << "Name:\t" << monsterIndex[i].name << endl;
        cout << "Description:\n\t" << description << endl;
        cout << "Weight:\t" << monsterIndex[i].weight << " pound(s)" << endl;
        cout << "Height:\t" << monsterIndex[i].height << " feet" << endl;
        cout << "Last known location:\t" << monsterIndex[i].originLocation << endl;
        cout << "Danger level:\t" << monsterIndex[i].dangerLevel << endl;
        cout << "Weekly Care Information:" << endl;
        cout << "\t-Hours of care required:        " << monsterIndex[i].costWeekly.careHoursNeeded << endl;
        cout << "\t-Cost of care:                  $ " << fixed << setprecision(2) << monsterIndex[i].costWeekly.care << endl;
        cout << "\t-Food cost:                     $ " << fixed << setprecision(2) << monsterIndex[i].costWeekly.food << endl;
        cout << "\t-Grooming & Supplies Cost:      $ " << fixed << setprecision(2) << monsterIndex[i].costWeekly.supplies << endl;
    }
        cout << "------------------------------------------------------------------------" << endl; // Prints a line to separate the monster list from the menu.
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
    cout << "\n\nCOST OF EACH MONSTER FOR ONE WEEK:" << endl << endl;
    cout << left << setw(42) << "MONSTER" <<"CARE COST" << endl;
    double careCostTotal = 0;
    for(int i = 1; i <= monsterCount; i++){ // Iterates through the monster array and prints the name of each monster and the cost of care for that monster.
        double careCost = (monsterIndex[i].costWeekly.careHoursNeeded * monsterIndex[i].costWeekly.care) + monsterIndex[i].costWeekly.food + monsterIndex[i].costWeekly.supplies; 
        // ^ Calculates the total cost of care for the individual monster.
        careCostTotal += careCost;
        // ^ Calculates the total cost of care for all the monsters.

        cout << left << setw(30) << monsterIndex[i].name << "$" << right << setw(20) << fixed << setprecision(2) << careCost << endl; 
        // ^ Prints the name of the monster and the cost of care for that monster on the same line with the cost aligned to the right. 
    }
    cout << left << setw(30) << "Total" << "$" << right << setw(20) << fixed << setprecision(2) << careCostTotal << endl;
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
    cout << "\n\nWould you like to save your mosnter list to a file? (y/n)" << endl;
    char userInputChar;
    cin >> userInputChar;
    if (userInputChar == 'y' || userInputChar == 'Y'){ // If the user wants to save the monster array to a file, the user is prompted for a file name.
        cout << "What is the name of the file you want to save your creatures to?" << endl;
        cout << "FILENAME:\t";
        string fileName;
        cin.ignore();
        getline(cin, fileName);
        ofstream outputFile(fileName); // Opens the file for output.
        if (outputFile.is_open()){ // If the file is open, the monster array is written to the file.
            for(int i = 1; i <= monsterCount; i++){
                outputFile << monsterIndex[i].name << '#';
                outputFile << monsterIndex[i].description << '#';
                outputFile << monsterIndex[i].weight << '#';
                outputFile << monsterIndex[i].height << '#';
                outputFile << monsterIndex[i].originLocation << '#';
                outputFile << monsterIndex[i].dangerLevel << '#';
                outputFile << monsterIndex[i].costWeekly.careHoursNeeded << '#';
                outputFile << monsterIndex[i].costWeekly.care << '#';
                outputFile << monsterIndex[i].costWeekly.food << '#';
                outputFile << monsterIndex[i].costWeekly.supplies << '#';
            }
            outputFile.close(); // Closes the file.
            cout << "Your monster list has been saved to " << fileName << endl;
        }
        else{ // If the file is not open, the user is notified.
            cout << "Sorry, the file could not be opened." << endl;
        }
    }
}