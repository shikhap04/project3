#include "moa.h"
#include "sorting.h"

using namespace std;

// Command to run program 
// g++ -std=c++14 -o build/moa src/main.cpp src/accidentNode.cpp src/moa.cpp src/sorting.cpp && ./build/moa.exe

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

    moa application;

    cout << "\nWelcome to Masters of the Air! \n";
    cout << "By: Shikha Patel and Jay Maisuria\n";
    cout << "A searchable database of all flight accidents in the U.S. from 01/2008 to 02/2024.\n" << endl;
    // printHelpMenu();

    bool runMOA = true;
    string currCMD;

    while (runMOA) {
        cout << "\nPlease enter a command: ";
        getline(cin, currCMD);

        if (currCMD == "Set Parameters" || currCMD == "set parameters" || currCMD == "Set Parameter" || currCMD == "set parameter" || currCMD == "Set parameter") {
            application.getParameters();
        }
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
        else if (currCMD == "Print All" || currCMD == "print all"){
            application.printAll();
        }
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
        else if (currCMD == "Current Data Info" || currCMD == "current data info") {
            cout << "Size of current dataset is: " << application.getSizeSearched() << "\n";
            cout << "Current Info Style is: " << application.getInfoStyle() << "\n";
            application.printInputs();

        }
        else if (currCMD == "Help" || currCMD == "help"){
            printHelpMenu();
        }
        else if (currCMD == "Reset" || currCMD == "reset"){
            application.reset();
            cout << "Reset Successful!\n";
            cout << "Now reverting to all data available\n";
            cout << "Current Data Set Size: " << application.getSizeSearched() << "\n";
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

