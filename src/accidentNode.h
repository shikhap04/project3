#pragma once

#include <iostream>
#include <string>

using namespace std;

class accidentNode {
private:
    // Data that needs to be stored in each node
    string EVID;
    string NTSB;
    
    string time;
    int day;
    int month;
    int year;

    string longitude;
    string latitude;

    string injuryType;
    int injuryCount;

    string city;
    string state;

    string weatherCond;
    string planeModel;

    // Reformatting data so that it is readable to the user
    string reformatTime();
    string reformatIntNull(int& value);
    string reformatNull(string& value);

public:
    // Constructors
    accidentNode();
    accidentNode(string EVID, string NTSB, int month, int day, int year, string time,  
        string city, string state, string longitude, string latitude, string weatherCond, string injuryType, int injuryCount,
        string planeModel);
    
    // Getters for Node information
    int getYear() {return year;}
    int getMonth() {return month;}
    int getDay() {return day;}
    string getCity() {return city;}
    string getState() {return state;}
    string getWeatherCond() {return weatherCond;}
    string getInjType() {return injuryType;}
    int getInjCount() {return injuryCount;}

    // Various ways to print a single node
    void printWholeNode(); 
    void printInfo();
    void printImportantInfo();
};
