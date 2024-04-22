#pragma once

#include <iomanip>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iterator>
#include "accidentNode.h"
#include "sorting.h"

using namespace std;



class moa {
private:
    // Initializes sorting class as an object to leverage sorting class functions
    sorting sorter;

    // A copy of all the data in the csv file, all data that matches the input, and a unordered map for all the inputs
    vector<accidentNode> allData;
    vector<accidentNode> searchedData;
    unordered_map<string, string> inputs;

    // Variables for info type, size of data, and a bool for whether the search has already occured
    int infoType;
    int allDataSize;
    bool searchedAlready;
    
    // Vector to verify if the state inputted exists
    vector<std::string> usStateAbbre = {
        "AL", "AK", "AS", "AZ", "AR", "CA", "CO", "CT", "DE", "DC",
        "FM", "FL", "GA", "GU", "HI", "ID", "IL", "IN", "IA", "KS",
        "KY", "LA", "ME", "MH", "MD", "MA", "MI", "MN", "MS", "MO",
        "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "MP",
        "OH", "OK", "OR", "PW", "PA", "PR", "RI", "SC", "SD", "TN",
        "TX", "UT", "VT", "VI", "VA", "WA", "WV", "WI", "WY"
    };

    // Functions
    void parsing();
    void search();
    void runSorts();

public:
    // Constructor
    moa();

    // Functions for the interface
    void getParameters();
    int getSizeSearched();
    int getInfoStyle();
    void setinfoType(int& num);
    void printTopXInfo(int& num);
    void printAll();
    void printInputs();
    void reset();
};