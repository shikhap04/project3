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
    

    void parsing();
    void search();
    void runSorts();

public:
    moa();
    void setinfoType(int& num);
    void getParameters();
    void printTopXInfo(int& num);
    void printAll();
    int getSizeSearched();
    void reset();
};