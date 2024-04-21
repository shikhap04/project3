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

public:
    accidentNode();
    accidentNode(string EVID, string NTSB, int month, int day, int year, string time,  
        string city, string state, string longitude, string latitude, string weatherCond, string injuryType, int injuryCount,
        string planeModel);

    void printWholeNode();

    //~accidentNode();
};