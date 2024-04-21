#pragma once

#include <iostream>
#include <string>

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
    
    int getYear() {return year;}
    int getMonth() {return month;}
    int getDay() {return day;}
    string getCity() {return city;}
    string getState() {return state;}
    string getWeatherCond() {return weatherCond;}
    string getInjType() {return injuryType;}
    int getInjCount() {return injuryCount;}

    void printWholeNode(); // NEED TO FIX -1 TO PRINT NULL

    //~accidentNode();
};