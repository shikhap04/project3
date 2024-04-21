#include <iostream>
#include "moa.h"

using namespace std;


/*
g++ -std=c++14 -o build/test src/main.cpp src/accidentNode.cpp src/moa.cpp && ./build/test
USER INTERFACE HERE
- initialize program (make sure big vector is created once)
- print to CLI options
- read parameters
- call search parameters in moa
- (somehow gets small vector, probably return in search parametrs or sort parameters)
- prints first x number of elements in small vector
*/

int main () {

    moa test;
    

    vector<pair<string, string>> inputs;

    string city;
    string state; 
    unsigned int day;
    unsigned int month;
    unsigned int year;
    string injuryType;
    string weatherCond; 

    cout << "\nWelcome to Masters of the Air! ";
    cout << "A searchable database of all flight accidents in the U.S. from 01/2008 to 02/2024." << endl;

    cout << "\nSearchable criteria include any combinations of:";
    cout << "\n1. Year (2008-2024)";
    cout << "\n2. Month (1-12)";
    cout << "\n3. Day (1-31)";
    cout << "\n4. State (e.g. KA)";
    cout << "\n5. City (e.g. Detroit)";
    cout << "\n6. Weather Condition (Cler, Few, Scat, or Ovct)";
    cout << "\n7. Injury Type (None, Minr, Sers, or Fatl)";
    cout << "\nIf you would like to ignore a certain criteria please input -1. Any incorrect input may result in a failed search.";

    cout << "\nPlease press any key to continue and input your search criteria: " << endl;

    cout << "\nPlease input the searchable year (2008-2024) or any other value if you're not searching by year." << endl;
    cin >> year;

    if (year <= 2024 && year >= 2008) {

        string y = to_string(year);
        pair<string, string> temp("Year", y);
        inputs.push_back(temp);

        cout << "Please input the searchable month (1-12) or any other value if you're not searching by month." << endl;
        cin >> month;

        if (month <= 12 && month >= 1) {

            string m = to_string(month);
            pair<string, string> temp("Month", m);
            inputs.push_back(temp);

            cout << "Please input the searchable day (1-31) or any other value if you're not searching by day." << endl;
            cin >> day;

            if (day <= 31 && day >= 1) {

                string d = to_string(day);
                pair<string, string> temp("Day", d);
                inputs.push_back(temp);

            } else {

                cout <<  "Not searching by day -> " << day << endl;
            }

        } else {

            cout <<  "Not searching by month -> " << month << endl;
        }

    } 
    else {

        cout <<  "Not searching by year -> " << year << endl;
    }

    cout << "Please input the searchable state in abbreviated format (e.g. KA) or any other value if you're not searching by state." << endl;
    cin >> state;

    if (state.size() == 2) {

        pair<string, string> temp("State", state);
        inputs.push_back(temp);

        cout << "Please input the searchable city (e.g. Detroit) or -1 if you're not searching by city." << endl;
        cin >> city;

        if (city != "-1") {

            pair<string, string> temp("State", city);
            inputs.push_back(temp);

        } else {

            cout <<  "Not searching by city -> " << city << endl;
        }

    } else {

        cout <<  "Not searching by state -> " << state << endl;
    }

    cout << "Please input the searchable weather condition or any other value if you're not searching by weather conditions." << endl;
    cin >> weatherCond;

    if (weatherCond == "Cler" || weatherCond == "Few" || weatherCond == "Scat" || weatherCond == "Ovct") {

        pair<string, string> temp("Sky Condition", weatherCond);
        inputs.push_back(temp);
    }
    else {

        cout << "Not searching by weatherCond -> " << weatherCond << endl;
    }
    
    cout << "Please input the searchable injury type or any other value if you're not searching by injury type." << endl;
    cin >> injuryType;

    if (injuryType == "None" || injuryType == "Minr" || injuryType == "Sers" || injuryType == "Fatl") {

        pair<string, string> temp("Highest Injury", injuryType);
        inputs.push_back(temp);
    }
    else {

        cout << "Not searching by injuryType -> " << injuryType << endl;
    }

    cout << "\n";
    for (int i = 0; i < inputs.size(); i++) {
        cout << inputs[i].second << endl;
    }

    test.search(inputs);

    return 0;

}