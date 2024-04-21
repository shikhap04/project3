#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
#include "accidentNode.h"

using namespace std;

accidentNode::accidentNode() {

    EVID = "null";
    NTSB = "null";

    time = "null";
    day = 0;
    month = 0;
    year = 0;

    longitude = "null";
    latitude = "null";

    injuryType = "null";
    injuryCount = 0;

    city = "null";
    state = "null";

    weatherCond = "null";
    planeModel = "null";
}

accidentNode::accidentNode(string EVID, string NTSB, int month, int day, int year, string time,  
        string city, string state, string longitude, string latitude, string weatherCond, string injuryType, int injuryCount,
        string planeModel) {
    this->EVID = EVID;
    this->NTSB = NTSB;

    this->time = time;
    this->day = day;
    this->month = month;
    this->year = year;

    this->longitude = longitude;
    this->latitude = latitude;

    this->injuryType = injuryType;
    this->injuryCount = injuryCount;

    this->city = city;
    this->state = state;

    this->weatherCond = weatherCond;
    this->planeModel = planeModel;
}

void accidentNode::printWholeNode() {
    string timeFormat;
    if (time.size() == 4) {
        timeFormat.append(1, time[0]);
        timeFormat.append(1, time[1]);
        timeFormat.append(1, ':');
        timeFormat.append(1, time[2]);
        timeFormat.append(1, time[3]);

    }
    if (time.size() == 3) {
        timeFormat.append(1, '0');
        timeFormat.append(1, time[0]);
        timeFormat.append(1, ':');
        timeFormat.append(1, time[1]);
        timeFormat.append(1, time[2]);
    }

    

    cout << EVID << " " << NTSB << " " << month << " " << day << " " << year << " " << timeFormat << " " << city << " " << state 
    << " " << longitude << " " << latitude << " " << weatherCond << " " << injuryType << " " << injuryCount << " " << planeModel << "\n";
}
    
//accidentNode::~accidentNode() {}
