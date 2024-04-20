#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include "moa.h"

using namespace std;

/*
program class
- constructor parses and makes the vector of nodes
- get search parameter (function called in main)
    - maybe it stores parameters in the object itself (when get new parameters, it sets everything else to null/-1)
- does search
- then does sort
    - heap sort
    - quick sort
- return small sorted vector to main
*/


moa::moa() {
    allDataSize = 0;
}


// ATTEMPTING TO BRANCH
void moa::parsing() {
    fstream file("input/accidentsData.csv");
    if(!file.is_open()) {cout << "FILE OPENING ERROR!";}

    vector<string> row;
    string line, value;

    //getline(file, line);

    while (!file.eof()) {
        row.clear();
        getline(file, line);

        istringstream stream(line);

        while (getline(stream, value, ',')) {
            row.push_back(value);
        }
        
        accidentNode temp();
        // stoi(row[0]), row[1], 
        cout << "\n";
    }
}

/*
    int EVID;
    string NTSB;

    int time;
    unsigned int day;
    unsigned int month;
    unsigned int year;

    string longitude;
    string latitude;

    string injuryType;
    unsigned int injuryCount;

    string city;
    string state;

    string weatherCond;
    string planeCompany;
    string planeModel;*/