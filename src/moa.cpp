#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iterator>
#include <chrono>
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
    infoType = 2;
    searchedAlready = false;
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

void moa::search() {
    searchedAlready = true;
    searchedData.clear();
    if (inputs.size() == 0) {
        searchedData = allData;
        //cout << "Number of accidents that meet the criteria: " << searchedData.size() << "\n";
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
}

void moa::runSorts() {

    auto quickStart = chrono::high_resolution_clock::now();
    sorter.quickSort(0, searchedData.size() - 1);
    auto quickStop = chrono::high_resolution_clock::now();

    auto quickDuration = chrono::duration_cast<chrono::microseconds> (quickStop - quickStart);

    auto heapStart = chrono::high_resolution_clock::now();
    sorter.heapSort();
    auto heapStop = chrono::high_resolution_clock::now();

    auto heapDuration = chrono::duration_cast<chrono::microseconds> (heapStop - heapStart);
 
    cout << "Number of accidents that meet the criteria: " << searchedData.size() << "\n";
    cout << "Heap time: " << heapDuration.count() << " microseconds  Quick time: " << quickDuration.count() << " microseconds \n";

}

void moa::setinfoType(int& num) {
    infoType = num;
}

void moa::getParameters() {

    searchedAlready = false;
    inputs.clear();
    string city;
    string state; 
    string day;
    string month;
    string year;
    string injuryType;
    string weatherCond; 

    cout << "\nSearchable criteria include any combinations of:";
    cout << "\n1. Year (2008-2024)";
    cout << "\n2. Month (1-12)";
    cout << "\n3. Day (1-31)";
    cout << "\n4. State (e.g. MI)";
    cout << "\n5. City (e.g. Detroit)";
    cout << "\n6. Weather Condition (Cler, Few, Scat, or Ovct)";
    cout << "\n7. Injury Type (None, Minr, Sers, or Fatl)";
    cout << "\nIf you would like to ignore a certain criteria please input -1. Any incorrect input may result in a failed search.";

    cout << "\nPlease press any key to continue and input your search criteria: " << endl;

    cout << "\nPlease input the searchable year (2008-2024) or any other value if you're not searching by year." << endl;
    cin >> year;
    bool isYearNum = true;

    for (auto i: year) {
        if(!isdigit(i)) {
            isYearNum = false;
            break;
        }
    }

    if (isYearNum == true && stoi(year) <= 2024 && stoi(year) >= 2008) {
        inputs.emplace("Year", year);

        cout << "Please input the searchable month (1-12) or any other value if you're not searching by month." << endl;
        cin >> month;
        bool isMonthNum = true;

        for (auto i: month) {
            if(!isdigit(i)) {
                isMonthNum = false;
                break;
            }
        }
        if (isMonthNum == true && stoi(month) <= 12 && stoi(month) >= 1) {
            inputs.emplace("Month", month);

            cout << "Please input the searchable day (1-31) or any other value if you're not searching by day." << endl;
            cin >> day;
            bool isDayNum = true;

            for (auto i: day) {
                if(!isdigit(i)) {
                    isDayNum = false;
                    break;
                }
            }

            if (isDayNum == true && stoi(day) <= 31 && stoi(day) >= 1) {
                inputs.emplace("Day", day);
            } 
            else {
                cout <<  "Not searching by day -> " << day << endl;
            }

        } else {
            cout <<  "Not searching by month -> " << month << endl;
        }

    } 
    else {
        cout <<  "Not searching by year -> " << year << endl;
    }

    cout << "Please input the searchable state in abbreviated format (e.g. MI) or any other value if you're not searching by state." << endl;
    cin >> state;

    if (state.size() == 2) {

        inputs.emplace("State", state);

        cout << "Please input the searchable city (e.g. Detroit) or -1 if you're not searching by city." << endl;
        //cin >> city;
        getline(cin >> ws, city);

        if (city != "-1") {
            inputs.emplace("City", city);
        } 
        else {
            cout <<  "Not searching by city -> " << city << endl;
        }
    } 
    else {
        cout <<  "Not searching by state -> " << state << endl;
    }

    cout << "Please input the searchable weather condition or any other value if you're not searching by weather conditions." << endl;
    cin >> weatherCond;

    if (weatherCond == "CLER" || weatherCond == "FEW" || weatherCond == "SCAT" || weatherCond == "OVCT") {
        inputs.emplace("Sky Condition", weatherCond);
    }
    else {
        cout << "Not searching by weatherCond -> " << weatherCond << endl;
    }
    
    cout << "Please input the searchable injury type or any other value if you're not searching by injury type." << endl;
    getline(cin >> ws, injuryType);

    if (injuryType == "NONE" || injuryType == "MINR" || injuryType == "SERS" || injuryType == "FATL") {
        inputs.emplace("Highest Injury", injuryType);
    }
    else {
        cout << "Not searching by injuryType -> " << injuryType << endl;
    }

    cout << "Number of Inputs is: " << inputs.size() << "\n";
    
}

void moa::printTopXInfo(int& num) { 
    if (!searchedAlready) {
        search(); 
    }
    else if (searchedAlready && searchedData.size() == 0) {
        cout << "No entries match parameters, please try again";
        return;
    }
    //if (searchedData.size() == 0) sorter.setData(allData);
    //else sorter.setData(searchedData);
    sorter.setData(searchedData);

    if (searchedData.size() <= num || num <= 0) {
        cout << "Number is invalid! Try again, valid range is 0 to " << searchedData.size() << "\n";
        return;
    }
    runSorts();
    sorter.print(infoType, num);
}

void moa::printAll() {
    if (!searchedAlready) {
        search(); 
    }
    else if (searchedAlready && searchedData.size() == 0) {
        cout << "No entries match parameters, please try again";
        return;
    }
    //if (searchedData.size() == 0) sorter.setData(allData);
    //else sorter.setData(searchedData);
    sorter.setData(searchedData);
    runSorts();
    sorter.print(infoType, -1);
}

int moa::getSizeSearched() {
    if (!searchedAlready) {
        search();
        searchedAlready = true;
    }
    if (!searchedAlready) return allDataSize;
    return searchedData.size();
}

void moa::reset() {
    inputs.clear();
    searchedData.clear();
    searchedAlready = false;
    infoType = 2;
    cout << "Reset Successful!\n";
    cout << "Current Data Set Size: " << searchedData.size() << "\n";
    cout << "Now reverting to all data available\n";
}
