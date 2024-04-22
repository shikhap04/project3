#include "moa.h"
#include "sorting.h"

using namespace std;

void printHelpMenu() {
    cout << "Here is a list of possible commands and what they do\n\n";
    cout << "Set Parameter: Allows you to enter parameters to search by.\n";
    cout << "Print Top X: Prints top entered amount of accidents matching the criteria\n";
    cout << "Print All: Prints all accidents matching the criteria\n";
    cout << "Set Info Style: Allows you to choose style of information printed\n";
    cout << "Help: Shows this dictionary.\n";
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
        if (currCMD == "Set Parameters") {
            application.getParameters();
        }
        else if (currCMD == "Print Top X"){
            // needs to do search, sort, and print
            string numShow;
            cout << "Please enter number of accidents to show: ";
            getline(cin, numShow);
            int num = stoi(numShow);
            application.printTopXInfo(num);
        }
        else if (currCMD == "Print All"){
            application.printAll();
        }
        else if (currCMD == "Set Info Style"){
            string infoType;
            cout << "Choose 1 to see all information available, 2 to see date, location, weather, injury, and plane information, 3 to see date, location and injury\n";
            cout << "Info Style: ";
            getline(cin, infoType);
            int num = stoi(infoType);
            application.setinfoType(num);
            
        }
        else if (currCMD == "Size") {
            cout << application.getSizeSearched() << "\n";
        }
        else if (currCMD == "Help"){
            printHelpMenu();
        }
        else if (currCMD == "Reset"){
            application.reset();
        }
        else if (currCMD == "End" || currCMD == "Stop"){
            cout << "Thank you for using Masters of the Air!\n";
            runMOA = false;
        }
        else {
            cout << "This is not a valid command, please enter Help to see command list or Stop to end the program\n";
        }

    }
    return 0;
}

/*
Set parameter
- run parameters message
Reset Parameter
- empty input vector
- success message
print top X
- ask how many they want to print
- print that many
print all
- print all 
help
- cmds and their description
end program
- run MOA false
*/


// /*
// g++ -std=c++14 -o build/test src/main.cpp src/accidentNode.cpp src/moa.cpp src/sorting.cpp && ./build/test
// USER INTERFACE HERE
// - initialize program (make sure big vector is created once)
// - print to CLI options
// - read parameters
// - call search parameters in moa
// - (somehow gets small vector, probably return in search parametrs or sort parameters)
// - prints first x number of elements in small vector
// */


// int main () {

//     moa test;
    
//     unordered_map<string, string> inputs;

//     string city;
//     string state; 
//     string day;
//     string month;
//     string year;
//     string injuryType;
//     string weatherCond; 

//     cout << "\nWelcome to Masters of the Air! ";
//     cout << "A searchable database of all flight accidents in the U.S. from 01/2008 to 02/2024." << endl;

//     cout << "\nSearchable criteria include any combinations of:";
//     cout << "\n1. Year (2008-2024)";
//     cout << "\n2. Month (1-12)";
//     cout << "\n3. Day (1-31)";
//     cout << "\n4. State (e.g. MI)";
//     cout << "\n5. City (e.g. Detroit)";
//     cout << "\n6. Weather Condition (Cler, Few, Scat, or Ovct)";
//     cout << "\n7. Injury Type (None, Minr, Sers, or Fatl)";
//     cout << "\nIf you would like to ignore a certain criteria please input -1. Any incorrect input may result in a failed search.";

//     cout << "\nPlease press any key to continue and input your search criteria: " << endl;

//     cout << "\nPlease input the searchable year (2008-2024) or any other value if you're not searching by year." << endl;
//     cin >> year;
//     bool isYearNum = true;

//     for (auto i: year) {
//         if(!isdigit(i)) {
//             isYearNum = false;
//             break;
//         }
//     }

//     if (isYearNum == true && stoi(year) <= 2024 && stoi(year) >= 2008) {

//         inputs.emplace("Year", year);

//         cout << "Please input the searchable month (1-12) or any other value if you're not searching by month." << endl;
//         cin >> month;
//         bool isMonthNum = true;

//         for (auto i: month) {
//             if(!isdigit(i)) {
//                 isMonthNum = false;
//                 break;
//             }
//         }
//         if (isMonthNum == true && stoi(month) <= 12 && stoi(month) >= 1) {

//             inputs.emplace("Month", month);

//             cout << "Please input the searchable day (1-31) or any other value if you're not searching by day." << endl;
//             cin >> day;
//             bool isDayNum = true;

//             for (auto i: day) {
//                 if(!isdigit(i)) {
//                     isDayNum = false;
//                     break;
//                 }
//             }

//             if (isDayNum == true && stoi(day) <= 31 && stoi(day) >= 1) {

//                 inputs.emplace("Day", day);

//             } else {

//                 cout <<  "Not searching by day -> " << day << endl;
//             }

//         } else {

//             cout <<  "Not searching by month -> " << month << endl;
//         }

//     } 
//     else {

//         cout <<  "Not searching by year -> " << year << endl;
//     }

//     cout << "Please input the searchable state in abbreviated format (e.g. MI) or any other value if you're not searching by state." << endl;
//     cin >> state;

//     if (state.size() == 2) {

//         inputs.emplace("State", state);

//         cout << "Please input the searchable city (e.g. Detroit) or -1 if you're not searching by city." << endl;
//         //cin >> city;
//         getline(cin >> ws, city);

//         if (city != "-1") {

//             inputs.emplace("City", city);

//         } else {

//             cout <<  "Not searching by city -> " << city << endl;
//         }

//     } else {

//         cout <<  "Not searching by state -> " << state << endl;
//     }

//     cout << "Please input the searchable weather condition or any other value if you're not searching by weather conditions." << endl;
//     cin >> weatherCond;

//     if (weatherCond == "CLER" || weatherCond == "FEW" || weatherCond == "SCAT" || weatherCond == "OVCT") {

//         inputs.emplace("Sky Condition", weatherCond);
//     }
//     else {

//         cout << "Not searching by weatherCond -> " << weatherCond << endl;
//     }
    
//     cout << "Please input the searchable injury type or any other value if you're not searching by injury type." << endl;
//     cin >> injuryType;

//     if (injuryType == "NONE" || injuryType == "MINR" || injuryType == "SERS" || injuryType == "FATL") {

//         inputs.emplace("Highest Injury", injuryType);
//     }
//     else {

//         cout << "Not searching by injuryType -> " << injuryType << endl;
//     }

//     cout << "\n";

//     test.search(inputs);
//     test.runSorts(1);

//     return 0;

// }