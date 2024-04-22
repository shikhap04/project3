#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>
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

string accidentNode::reformatTime() {
    string timeFormat;
    if (time.size() == 4) {
        timeFormat.append(1, time[0]);
        timeFormat.append(1, time[1]);
        timeFormat.append(1, ':');
        timeFormat.append(1, time[2]);
        timeFormat.append(1, time[3]);

    }
    else if (time.size() == 3) {
        timeFormat.append(1, '0');
        timeFormat.append(1, time[0]);
        timeFormat.append(1, ':');
        timeFormat.append(1, time[1]);
        timeFormat.append(1, time[2]);
    }
    else if (time == "-1") {
        timeFormat = "Null";
    }
    else if (time.size() == 2) {
        timeFormat.append(1, time[0]);
        timeFormat.append(1, time[1]);
        timeFormat.append(1, ':');
        timeFormat.append(1, '0');
        timeFormat.append(1, '0');
    }
    else if (time.size() == 1) {
        timeFormat.append(1, '0');
        timeFormat.append(1, time[0]);
        timeFormat.append(1, ':');
        timeFormat.append(1, '0');
        timeFormat.append(1, '0');
    }

    return timeFormat;
}

string accidentNode::reformatIntNull(int& value) {
    if (value == -1) return "null";
    return to_string(value);
}

string accidentNode::reformatNull(string& value) {
    if (value == "-1") return "null";
    return value;
}

void accidentNode::printWholeNode() {
    string timeFormat = reformatTime();    

    cout << "EVID: "<< reformatNull(EVID) << " NTSB: " << reformatNull(NTSB) << " Date: " << reformatIntNull(month) << "/" << reformatIntNull(day) << "/" << reformatIntNull(year) << " " << timeFormat 
    << " Location: " << reformatNull(city) << ", " << reformatNull(state) << " Coordinates: " << reformatNull(longitude) << ", " << reformatNull(latitude)
    << " Weather: " << reformatNull(weatherCond) << " Worst Injury: " << reformatNull(injuryType) << "- " << reformatIntNull(injuryCount) << " Aircraft: " << reformatNull(planeModel) << "\n";
}

void accidentNode::printInfo() {
    string timeFormat = reformatTime();

    cout << "EVID: "<< reformatNull(EVID);
    cout << "  Date: " << reformatIntNull(month) << "/" << reformatIntNull(day) << "/" << reformatIntNull(year) << " " << timeFormat;
    cout << "  Location: " << reformatNull(city) << ", " << reformatNull(state);
    cout << "  Weather: " << reformatNull(weatherCond);
    cout << "  Worst Injury: " << reformatNull(injuryType) << ": " << reformatIntNull(injuryCount);
    cout << "  Plane: " << reformatNull(planeModel) << "\n";
}

void accidentNode::printImportantInfo() {
    string timeFormat = reformatTime();

    cout << "Date: " << reformatIntNull(month) << "/" << reformatIntNull(day) << "/" << reformatIntNull(year) << " " << timeFormat;
    cout << "  Location: " << reformatNull(city) << ", " << reformatNull(state);
    cout << "  Worst Injury: " << reformatNull(injuryType) << ": " << reformatIntNull(injuryCount) << "\n";
}
    
//accidentNode::~accidentNode() {}
