#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

class accidentNode {
private:
    int time;
    unsigned int day;
    unsigned int month;
    unsigned int year;

    string injuryType;
    unsigned int injuryCount;

    string city;
    string state;

    string weatherCond;
    string planeCompany;
    string planeModel;

public:
    accidentNode();
    accidentNode(int time, unsigned int day, unsigned int month, unsigned int year, 
        string injuryType, unsigned int injuryCount, string city, string state, 
        string weatherCond, string planeCompany, string planeModel);

    ~accidentNode();
};