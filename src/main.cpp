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

    cout << "\nSearchable criteria include any combinations of:" << endl;
    cout << "Day, Month, Year, City, State, Injury Type, Weather Conditions, Aircraft Company, and Aircraft Model." << endl;
    
    cout << "\nPlease press any key to continue and input your search criteria: " << endl;

    cout << "Please input the searchable year (2008-2024) or any other value if you're not searching by year." << endl;
    cin >> year;
    if (year <= 2024 && year >= 2008) {
        string y = to_string(year);
        pair<string, string> temp("Year", y);
        inputs.push_back(temp);

        cout << "Please input the searchable month (1-12) or any other value if you're not searching by year." << endl;
        cin >> month;
        if (month <= 12 && month >= 1) {
            string m = to_string(month);
            pair<string, string> temp("Year", y);
            inputs.push_back(temp);
        } else {
            cout <<  "Not searching by month -> " << month;
        }

    } else {
        cout <<  "Not searching by date -> " << year;
    }
    

    return 0;
}