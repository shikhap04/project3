# Masters of Air!
By Shikha Patel and Jay Maisuria

## Project Description
This project is a application to search and sort a dataset of aviation accidents from 2008-2024 according to a set of parameters.
// Gets inputs for weather conditions and ensures it is properly inputted as one of the available options
It allows a user to input and set parameters such as date, location, weather, and injury type, and returns a list of accidents that match that criteria, sorted by the worst accidents to least, if no parameters are set, it searches through the entire dataset and returns a sorted list. 

There are also options to set the style of information printed, get info about the dataset that meets the current parameters, reset the application and its parameters, output a help menu that describes the commands and their functions.

The user is able to see the data by printing all of the accidents that meet the criteria or print top X worst accidents by injury count that meet the criteria.

## Instructions
To compile and run the program, run these commands in the project directory:
```
g++ -std=c++14 -o build/moa src/main.cpp src/accidentNode.cpp src/moa.cpp src/sorting.cpp

./build/moa.exe
```

Here is a list of possible commands and what they do, the commands are have to be inputted as displayed. 

**Set Parameter:** Prompts for different parameters to search by, and will output number of parameters that meet the criteria.
  - Year- Valid year must be between 2008-2024, if not valid, it will skip forwards to prompting for state
  - Month- Must be an number 1-12 for corresponding months, will search for month within previously given year
  - Date- Must be a number 1-31 for corresponding day
  - State- Must be a valid state or American terrorities abbreviation, if not it will skip forward to prompt for a weather condition
  - City- Will search for a city within the state previously given
  - Weather Condition: Will search for a given weather condition, options to input are Cler, Few, Scat, and OVCT which means clear, few clouds, scattered clouds, and overcast clouds respectively
  - Injury Type: Will search for worst injury type, options to input are None, Minr, Sers, and Fatl, which mean no injuries, minor injuries, serious injuries, and fatal injuries respecitvely. 

**Print Top X:** Prompts for a number, X, so that it can display the top X accidents that meet the current criteria. Prints the top X accidents by injury count if no parameters have been set. Also will print time in microseconds that each sort took.

**Print All:** Displays all accidents that meet the current criteria. Prints all accidents in dataset if no parameters have been set. Also will print time in microseconds that each sort took.

**Set Info Style:** Allows you to choose style of information printed with the default being 2. 
1. Whole Node (EVID, NTSB, Date, Time, City, State, Longitude, Latitude, Weather Condition, Worst injury type, Number of Injuries, Aircraft Model)
    EVID: 20110412X23201 NTSB: DCA11LA045 Date: 4/12/2011 06:00 Location: Jamaica, NY Coordinates: 403821N, 0734722W Weather: FEW Worst Injury: NONE- 576 Aircraft: CRJ
2. General Info (EVID, Date, Time, City, State, Weather Condition, Worst injury type, Number of Injuries, Aircraft Model)
    EVID: 20110412X23201 Date: 4/12/2011 06:00  Location: Jamaica, NY  Weather: FEW  Worst Injury: NONE: 576  Plane: CRJ
3. Critical Info (Date, Time, City, State, Worst injury type, Number of Injuries)
    Date: 4/12/2011 06:00  Location: Jamaica, NY  Worst Injury: NONE: 576

**Help:** Displays a short list of command options and their descriptions

**Current Data Info:** Prints the size of searched data, current info style, number of inputs and list of parameters and their values

**Reset:** Resets the program so that the searched data and inputs is cleared and the info style is set to default.

**Stop/End:** Ends the program

## Contributions
**Shikha:** Heap Sort, Organizing CSV File, Parsing, Search and Sorting, Printing

**Jay:** Quick Sort, Command Line Interface, Report

## References
- [NTSB Data Set](https://www.ntsb.gov/safety/data/Pages/Data_Stats.aspx)
- Professor Aman's Class Slides
