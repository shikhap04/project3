#include "moa.h"
#include "sorting.h"

using namespace std;

// Command to run program 
// g++ -std=c++14 -o build/moa src/main.cpp src/accidentNode.cpp src/moa.cpp src/sorting.cpp && ./build/moa.exe

// Help Menu
void printHelpMenu() {
    cout << "Here is a list of possible commands and what they do.\n\n";
    cout << "Set Parameter: Allows you to enter parameters to search by.\n";
    cout << "Print Top X: Prints top entered amount of accidents matching the criteria.\n";
    cout << "Print All: Prints all accidents matching the criteria.\n";
    cout << "Set Info Style: Allows you to choose style of information printed.\n";
    cout << "Help: Shows this menu.\n";
    cout << "Current Data Info: Prints the size of searched data, current info style, number of inputs and list of parameters and their values.\n";
    cout << "Reset: Resets the program.\n";
    cout << "Stop: Ends the program. \n";
}

int main() {
    // Initializes moa program
    moa application;

    // Welcome messages
    cout << "\nWelcome to Masters of the Air! \n";
    cout << "By: Shikha Patel and Jay Maisuria\n";
    cout << "A searchable database of all flight accidents in the U.S. from 01/2008 to 02/2024." << endl;

    // Variables for while loop
    bool runMOA = true;
    string currCMD;

    // Asks for commands repeatedly
    while (runMOA) {
        cout << "\nPlease enter a command: ";
        getline(cin, currCMD);

        // If command is set parameter, it runs get parameter in the moa program
        if (currCMD == "Set Parameters" || currCMD == "set parameters" || currCMD == "Set Parameter" || currCMD == "set parameter" || currCMD == "Set parameter") {
            application.getParameters();
        }

        // Prompts for a value and reads it
        //Validates that a number is inputted and calls print top X in moa program
        else if (currCMD == "Print Top X" || currCMD == "Print Top x" || currCMD == "print top x"){
            // needs to do search, sort, and print
            string numShow;
            cout << "Please enter number of accidents to show: \n";
            getline(cin, numShow);
            bool isNum = true;
            for (auto i : numShow) {
                if(!isdigit(i)) {
                    cout << "Not a number! Please try again\n";
                    isNum = false;
                    break;
                }
            }
            if (isNum) {
                int num = stoi(numShow);
                application.printTopXInfo(num);
            }
        }

        // Calls print all in moa program
        else if (currCMD == "Print All" || currCMD == "print all"){
            application.printAll();
        }

        // Prompts and reads for which info style and then runs set info style in moa application
        else if (currCMD == "Set Info Style" || currCMD == "set info style"){
            string infoType;
            cout << "Input 1 to see all information available\n";
            cout << "Input 2 to see EVID, date, location, weather, injury, and plane information\n";
            cout<< "Input 3 to see date, location and injury\n";
            cout << "Info Style: ";
            getline(cin, infoType);
            int num = stoi(infoType);
            application.setinfoType(num);
        }

        // Prints current data size, info style, and number of inputs and the variable name and value
        else if (currCMD == "Current Data Info" || currCMD == "current data info") {
            cout << "Size of current dataset is: " << application.getSizeSearched() << "\n";
            cout << "Current Info Style is: " << application.getInfoStyle() << "\n";
            application.printInputs();
        }

        // prints help menu
        else if (currCMD == "Help" || currCMD == "help"){
            printHelpMenu();
        }

        // Resets and get the size of the new vector (will always be all data)
        else if (currCMD == "Reset" || currCMD == "reset"){
            application.reset();
            cout << "Reset Successful!\n";
            cout << "Now reverting to all data available\n";
            cout << "Current Data Set Size: " << application.getSizeSearched() << "\n";
        }

        // ends the while loop
        else if (currCMD == "End" || currCMD == "Stop" || currCMD == "end" || currCMD == "stop"){
            cout << "Thank you for using Masters of the Air!\n";
            runMOA = false;
        }
        
        // incorrect command error message
        else {
            cout << "This is not a valid command, please enter Help to see command list or Stop to end the program\n";
        }

    }
    return 0;
}

