#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iterator>
#include <chrono>
#include "moa.h"

using namespace std;

//Constructor, parses csv file and sets defaults
moa::moa() {
    parsing();
    allDataSize = allData.size();
    infoType = 2;
    searchedAlready = false;
}

// Parses CSV file
void moa::parsing() {
    fstream file("input/accidentData.csv");
    if(!file.is_open()) {cout << "FILE OPENING ERROR!";}

    vector<string> row;
    string line, value;

    getline(file, line);

    // Iterates through each line of CSV
    while (!file.eof()) {
        row.clear();
        getline(file, line);

        istringstream stream(line);

        while (getline(stream, value, ',')) {
            row.push_back(value);
        }

        // Makes a node for each accident and adds to the vector that contains all the data        
        accidentNode temp(row[0], row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]), row[5],  
        row[6], row[7], row[8], row[9], row[10], row[11], stoi(row[12]), row[13]);

        allData.push_back(temp);
    }
}

// Searches through all data to find all nodes that matches the inputted parameters
void moa::search() {
    searchedAlready = true;
    searchedData.clear();

    if (inputs.size() == 0) { // if there are no input parameters, searched data needs to be all data
        searchedData = allData;
        return;
    }

    // Iterates through all data and then iterates through input unordered map to check if the node matches the value in the input unordered map
    for (int i = 0; i < allDataSize; i++) {
        bool addNode = true;

        for (auto iter : inputs) {
            string variable = iter.first;
            string value = iter.second;

            // Compares each variable and its value in input to current node values, if any comparison is false it continues to the next node
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
        if(addNode == true) searchedData.push_back(allData[i]); // if none of the comparisons where false, add it to the searched data
    }
}

// Runs the sorts on the searched data, and measures time taken. 
// Then prints the number of accidents that were in the searched data and time it took for each sort
void moa::runSorts() {
    auto quickStart = chrono::high_resolution_clock::now();
    sorter.quickSort(0, searchedData.size() - 1);
    auto quickStop = chrono::high_resolution_clock::now();

    auto quickDuration = chrono::duration_cast<chrono::nanoseconds> (quickStop - quickStart);

    auto heapStart = chrono::high_resolution_clock::now();
    sorter.heapSort();
    auto heapStop = chrono::high_resolution_clock::now();

    auto heapDuration = chrono::duration_cast<chrono::nanoseconds> (heapStop - heapStart);
 
    cout << "Number of accidents that meet the criteria: " << searchedData.size() << "\n";
    cout << "Heap time: " << heapDuration.count() << " nanoseconds  Quick time: " << quickDuration.count() << " nanoseconds \n";
}

// Gets parameters from users using a CLI and placing the given parameters into inputs
void moa::getParameters() {

    searchedAlready = false;
    inputs.clear(); // Clears any past inputs
    string city;
    string state; 
    string day;
    string month;
    string year;
    string weatherCond; 
    string injuryType;

    // Prints out all parameters and an example of each
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

    // checks if year is properly inputted as an int
    for (auto i: year) {
        if(!isdigit(i)) {
            isYearNum = false;
            break;
        }
    }

    // Gets inputs for year, month, day and makes sure inputs are properly inputted, ensures user cannot give month without year or day without month and year
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

    // Gets inputs for state and city and ensures state is inputted correctly as a valid abbreviation, ensures user cannot provide city without state
    cout << "Please input the searchable state in abbreviated format (e.g. MI) or any other value if you're not searching by state." << endl;
    cin >> state;
    if (state.size() == 2 && find(usStateAbbre.begin(), usStateAbbre.end(), state) != usStateAbbre.end()) {

        inputs.emplace("State", state);

        cout << "Please input the searchable city (e.g. Detroit) or \"None\" if you're not searching by city." << endl;
        getline(cin >> ws, city);

        if (city != "-1" && city != "None" && city != "none") {
            inputs.emplace("City", city);
        } 
        else {
            cout <<  "Not searching by city -> " << city << endl;
        }
    } 
    else {
        cout <<  "Not searching by state -> " << state << endl;
    }

    // Gets inputs for weather conditions and ensures it is properly inputted as one of the available options
    cout << "Please input the searchable weather condition or any other value if you're not searching by weather conditions." << endl;
    cin >> weatherCond;

    if (weatherCond == "CLER" || weatherCond == "FEW" || weatherCond == "SCAT" || weatherCond == "OVCT" ||
        weatherCond == "cler" || weatherCond == "few" || weatherCond == "scat" || weatherCond == "ovct" ||
        weatherCond == "Cler" || weatherCond == "Few" || weatherCond == "Scat" || weatherCond == "Ovct") {
        for (auto i : weatherCond) {
            i = toupper(i);
        }
        inputs.emplace("Sky Condition", weatherCond);
    }
    else {
        cout << "Not searching by weather condition -> " << weatherCond << endl;
    }
    
    // Gets inputs for injury type and ensures it is properly inputted as one of the available options
    cout << "Please input the searchable injury type or any other value if you're not searching by injury type." << endl;
    getline(cin >> ws, injuryType);

    if (injuryType == "NONE" || injuryType == "MINR" || injuryType == "SERS" || injuryType == "FATL" ||
        injuryType == "none" || injuryType == "minr" || injuryType == "sers" || injuryType == "fatl" ||
        injuryType == "None" || injuryType == "Minr" || injuryType == "Sers" || injuryType == "Fatl") {
        for (auto i : injuryType) {
            i = toupper(i);
        }
        inputs.emplace("Highest Injury", injuryType);
    }
    else {
        cout << "Not searching by Injury Type -> " << injuryType << endl;
    }
    printInputs();
    
}

// Sets info type
void moa::setinfoType(int& num) {
    infoType = num;
}

// Returns info type
int moa::getInfoStyle() {
    return infoType;
}

// If data hasn't been searched already, search it and then return size
int moa::getSizeSearched() {
    if (!searchedAlready) {
        search();
        searchedAlready = true;
    }
    return searchedData.size();
}

// Prints number of inputs and all parameters and its value
void moa::printInputs() {
    cout << "Number of Inputs is: " << inputs.size() << "\n";
    if (inputs.size() != 0) {
        cout << "Inputs are: \n";
        for (auto iter : inputs) {
        cout << iter.first << ": " << iter.second << "\n";
        }
    }
}

// If data hasn't been searched already, it searches it
// If searched and there are no entries that match the parameters, outputs an error message
// Validates number inputted is not below 0 or above the size of searched data
// Then ensures the sorting class has correct data and runs the sorts
// Only prints inputted number of entries
void moa::printTopXInfo(int& num) { 
    if (!searchedAlready) {
        search(); 
    }
    else if (searchedAlready && searchedData.size() == 0) {
        cout << "No entries match parameters, please try again";
        return;
    }
    if (num <= 0) {
        cout << "Number is invalid! Try again, valid range is 0 to " << searchedData.size() << "\n";
        return;
    }
    else if (searchedData.size() <= num) num = searchedData.size();
    sorter.setData(searchedData);
    runSorts();
    sorter.print(infoType, num);
}

// If data hasn't been searched already, it searches it
// If searched, but there are no entries that match the parameters, outputs an error message
// Then ensures the sorting class has correct data and runs the sorts
// Prints all entries
void moa::printAll() {
    if (!searchedAlready) {
        search(); 
    }
    else if (searchedAlready && searchedData.size() == 0) {
        cout << "No entries match parameters, please try again";
        return;
    }
    sorter.setData(searchedData);
    runSorts();
    sorter.print(infoType, -1);
}

// Reset inputs, searched data vector is emptied and defaults are reinstated
void moa::reset() {
    inputs.clear();
    searchedData.clear();
    searchedAlready = false;
    infoType = 2;
}
