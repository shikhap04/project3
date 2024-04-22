#include "moa.h"
#include "sorting.h"

using namespace std;

// Command to run program 
// g++ -std=c++14 -o build/moa src/main.cpp src/accidentNode.cpp src/moa.cpp src/sorting.cpp && ./build/moa.exe

void printHelpMenu() {
    cout << "Here is a list of possible commands and what they do\n\n";
    cout << "Set Parameter: Allows you to enter parameters to search by\n";
    cout << "Print Top X: Prints top entered amount of accidents matching the criteria\n";
    cout << "Print All: Prints all accidents matching the criteria\n";
    cout << "Set Info Style: Allows you to choose style of information printed\n";
    cout << "Help: Shows this menu\n";
    cout << "Size: Returns the size of searched data\n";
    cout << "Reset: Resets the program.\n";
    cout << "Stop: Ends the program \n";
}

int main() {

    moa application;

    cout << "\nWelcome to Masters of the Air! ";
    cout << "By: Shikha Patel and Jay Maisuria\n";
    cout << "A searchable database of all flight accidents in the U.S. from 01/2008 to 02/2024." << endl;
    // printHelpMenu();

    bool runMOA = true;
    string currCMD;

    while (runMOA) {
        cout << "Please enter a command: ";
        getline(cin, currCMD);
        if (currCMD == "Set Parameters" || currCMD == "set parameters" || currCMD == "Set Parameter" || currCMD == "set parameter") {
            application.getParameters();
        }
        else if (currCMD == "Print Top X" || currCMD == "Print Top x"){
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
        else if (currCMD == "Print All" || currCMD == "print all"){
            application.printAll();
        }
        else if (currCMD == "Set Info Style" || currCMD == "set info style"){
            string infoType;
            cout << "Choose 1 to see all information available, 2 to see date, location, weather, injury, and plane information, 3 to see date, location and injury\n";
            cout << "Info Style: ";
            getline(cin, infoType);
            int num = stoi(infoType);
            application.setinfoType(num);
            
        }
        else if (currCMD == "Size" || currCMD == "size") {
            cout << "Size of current dataset is: " << application.getSizeSearched() << "\n";
        }
        else if (currCMD == "Help" || currCMD == "help"){
            printHelpMenu();
        }
        else if (currCMD == "Reset" || currCMD == "reset"){
            application.reset();
            cout << "Reset Successful!\n";
            cout << "Current Data Set Size: " << application.getSizeSearched() << "\n";
            cout << "Now reverting to all data available\n";
        }
        else if (currCMD == "End" || currCMD == "Stop" || currCMD == "end" || currCMD == "stop"){
            cout << "Thank you for using Masters of the Air!\n";
            runMOA = false;
        }
        else {
            cout << "This is not a valid command, please enter Help to see command list or Stop to end the program\n";
        }

    }
    return 0;
}

