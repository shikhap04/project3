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
    vector<accidentNode> allData;
    vector<accidentNode> searchedData;
    int allDataSize;

public:
    moa();
    void parsing();
    void search(unordered_map<string, string>& inputs);
    void runSorts(int typeInfo);

};