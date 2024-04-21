#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iterator>
#include "accidentNode.h"

using namespace std;


class moa {
private:
    vector<accidentNode> allData;
    vector<accidentNode> searchedData;
    int allDataSize;

public:
    moa();
    void parsing();
    void search(vector<pair<string, string>>& inputs);

};