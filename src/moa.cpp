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
    parsing();
    allDataSize = allData.size();
    cout << "Full Data Set Size: " << allDataSize << "\n";
}

void moa::parsing() {
    fstream file("input/accidentData.csv");
    if(!file.is_open()) {cout << "FILE OPENING ERROR!";}

    vector<string> row;
    string line, value;

    getline(file, line);

    while (!file.eof()) {
        row.clear();
        getline(file, line);

        istringstream stream(line);

        while (getline(stream, value, ',')) {
            row.push_back(value);
        }
        
        accidentNode temp(row[0], row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]), row[5],  
        row[6], row[7], row[8], row[9], row[10], row[11], stoi(row[12]), row[13]);

        allData.push_back(temp);
    }
}

void moa::search(unordered_map<string, string>& inputs) {
    if (inputs.size() == 0) {
        searchedData = allData;
        return;
    }

    for(auto iter : inputs) {
        cout << iter.first << ":" << iter.second << "\n";
    }

    for (int i = 0; i < allDataSize; i++) {
        bool addNode = true;

        for (auto iter : inputs) {
            string variable = iter.first;
            string value = iter.second;

            if (variable == "Year" && (stoi(value)) != allData[i].getYear()) {
                addNode = false;
                break;
            }
            else if (variable == "Month" && (stoi(value)) != allData[i].getMonth()) {
                addNode = false;
                break;
            }
            else if (variable == "Day" && (stoi(value)) != allData[i].getDay()) {
                addNode = false;
                break;
            }
            else if (variable == "State" && value != allData[i].getState()) {
                addNode = false;
                break;
            }
            else if (variable == "City" && value != allData[i].getCity()) {
                addNode = false;
                break;
            }
            else if (variable == "Sky Condition" && value != allData[i].getWeatherCond()) {
                addNode = false;
                break;
            }
            else if (variable == "Highest Injury" && value != allData[i].getInjType()) {
                addNode = false;
                break;
            }
        }
        if(addNode == true) searchedData.push_back(allData[i]);
    }
    for (int i = 0; i < searchedData.size(); i++) {
        searchedData[i].printInfo();
    }
    cout << "searched size: " << searchedData.size() << "\n";
}

void moa::runSorts() {

}
/*
    string EVID;
    string NTSB;

    string time;
    int day;
    int month;
    int year;

    string longitude;
    string latitude;

    string injuryType;
    unsigned int injuryCount;

    string city;
    string state;

    string weatherCond;
    string planeModel;
    */