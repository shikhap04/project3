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

public:
    moa();
    void parsing();

};