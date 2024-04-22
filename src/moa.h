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
    sorting sorter;

    vector<accidentNode> allData;
    vector<accidentNode> searchedData;
    unordered_map<string, string> inputs;

    int infoType;
    int allDataSize;
    bool searchedAlready;
    
    vector<std::string> usStateAbbre = {
        "AL", "AK", "AS", "AZ", "AR", "CA", "CO", "CT", "DE", "DC",
        "FM", "FL", "GA", "GU", "HI", "ID", "IL", "IN", "IA", "KS",
        "KY", "LA", "ME", "MH", "MD", "MA", "MI", "MN", "MS", "MO",
        "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "MP",
        "OH", "OK", "OR", "PW", "PA", "PR", "RI", "SC", "SD", "TN",
        "TX", "UT", "VT", "VI", "VA", "WA", "WV", "WI", "WY"
    };

    void parsing();
    void search();
    void runSorts();
    void printInputs();

public:
    moa();
    void setinfoType(int& num);
    void getParameters();
    void printTopXInfo(int& num);
    void printAll();
    int getSizeSearched();
    void reset();
};