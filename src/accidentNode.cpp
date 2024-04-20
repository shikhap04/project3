#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
#include <accidentNode.h>

using namespace std;

accidentNode::accidentNode() {
    time = 0;
    day = 0;
    month = 0;
    year = 0;

    injuryType = "null";
    injuryCount = 0;

    city = "null";
    state = "null";

    weatherCond = "null";
    planeCompany = "null";
    planeModel = "null";
}

accidentNode::accidentNode(int time, unsigned int day, unsigned int month, unsigned int year, 
        string injuryType, unsigned int injuryCount, string city, string state, 
        string weatherCond, string planeCompany, string planeModel) {
    this->time = time;
    this->day = day;
    this->month = month;
    this->year = year;

    this->injuryType = injuryType;
    this->injuryCount = injuryCount;

    this->city = city;
    this->state = state;

    this->weatherCond = weatherCond;
    this->planeCompany = planeCompany;
    this->planeModel = planeModel;
}
    
accidentNode::~accidentNode() {}
