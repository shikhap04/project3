
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iterator>
#include <moa.h>

using namespace std;

/*
program class
- constructor parses and makes the vector of nodes
- get search parameter (function called in main)
    - maybe it stores parameters in the object itself (when get new parameters, it sets everything else to null/-1)
- does search
- then does sort
    - heap sort
    - quick sort
- return small sorted vector to main
*/


moa::moa() {

}


void moa::parsing() {
    fstream file("../input/accidentsData.csv");
    if(!file.is_open()) {cout << "FILE OPENING ERROR!"};
    // while (!file.eof()) {
        
    // }
}