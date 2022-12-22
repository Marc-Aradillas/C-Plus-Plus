//
// Marc Aradillas
// SNHU Class  : CS210-H7634 (Programming Languages)
// Description : (3-1 Project: Clock)
// Date: 15 November, 2022
//

// references: Stackoverflow, reddit threads, Sense feedback tool, zybooks ch. 3 & 4, announcement references (C++ Class & C++ Headers)
//link references: https://www.codespeedy.com/digital-clock-in-cpp/, 
// https://stackoverflow.com/questions/60369425/cannot-get-menu-selection-to-run-a-function-c


//include files
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
               // Private data can only be accessed by the methods in the class.
int hours = 0;          // This is the data, the purpose of the class.
int minutes = 0;        // The class encapsulates the data and the methods to access
int seconds = 0;        // the data in a single unit.

string twoDigitString(unsigned int n) {     //adds '0' in front of single digit numbers
    string number;
    if (n < 10)
        number.append(to_string(0)); // used .append to string for values of n if less than 10, (0-9)
    number.append(to_string(n));

    return number;
}

string nCharString(size_t n, char c) {      // reads number of characters and produces expected character choice | '*'
    string charString(n, c);
    return charString;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) { // Format time to military time.
    string milTime;

    milTime.append(twoDigitString(h) + ":"); // used .append to input value of the twoDigitString(h-s)
    milTime.append(twoDigitString(m) + ":");
    milTime.append(twoDigitString(s));

    return milTime;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) { // Format time to Standard time.

    int fixedTime = h;
    string stdTime;

    if (h > 12) {
        fixedTime = h - 12;
    }

    if (fixedTime == 0) {
        fixedTime = 12;
    }

    stdTime.append(twoDigitString(fixedTime) + ":"); //appended fixed time to read as two digits if updated
    stdTime.append(twoDigitString(m) + ":");
    stdTime.append(twoDigitString(s));

    if (h <= 11) {
        stdTime.append(" A M");
    }
    // attempted to ensure that my A M and P M printed accordingly
    // I found trouble when it came to printing for "12:00:01" & "11:00:59"
    // I tried using an additional conditional to try to append it to the outcome
    // but I let up and moved on from this point.
    else {
        stdTime.append(" P M");
    }

    return stdTime;
}

void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
    // first print width *'s followed by an endl
    string menuPrint;

    for (int i = 0; i < width; i++) {
        menuPrint = menuPrint + "*";
    }

    cout << menuPrint << endl;

    for (unsigned int i = 0; i < numStrings; i++) {
        string printString = "* " + to_string(i + 1) + " - " + strings[i];
        string endCharacter = nCharString(width - printString.length(), ' ') + "*";

        cout << printString << endCharacter << endl;
    }

    cout << menuPrint << endl;
}   // utilized 2 for loops to create the stars and spaced for menu
    // I set string to printString and endCharacter to populate string and characters between menu prompt verbiage

unsigned int getMenuChoice(unsigned int maxChoice) { //function for menu choices
    int getInput;
    while (1) {
        cin >> getInput;
        if ((getInput > 0) && (getInput <= 4)) // maxChoice presented a sigend/unsigned value, since the input max choice is to 4 i changed it accordingly
            return getInput;
    }
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) { //Displays both 12 and 24 hour clocks
    //nCharString to create display for required number of spaces per Chada tech Specs
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}
// set up get and set for time values
int getSecond() {
    return seconds;
}

int getMinute() {
    return minutes;
}

int getHour() {
    return hours;
}
//Setters for  hours minutes and seconds to retrieve return value for specific int variable
void setSecond(int sec) {
    seconds = sec;
}

void setMinute(int min) {
    minutes = min;
}
    
void setHour(int currentHour) {
    hours = currentHour;
}

void addOneHour() {
    int hour = getHour();

    if (hour >= 0 && hour <= 22) {
        hour++;
        setHour(hour);
    }

    else if (hour == 23) {
        hour = 0;
        setHour(hour);
    }
}

void addOneMinute() {
    int minute = getMinute();

    if (minute >= 0 && minute <= 58) {
        minute++;
        setMinute(minute);
    }

    else if (minute == 59) {
        minute = 0;
        setMinute(minute);
        addOneHour();
    }
}

void addOneSecond() {
    int second = getSecond();

    if (second >= 0 && second <= 58) {
        second++;
        setSecond(second);
    }

    else if (second == 59) {
        second = 0;
        setSecond(second);
        addOneMinute();
    }
}

void mainMenu() {

    while (1) { //utilized a while-if block for menu options and created 4 selectable options per CHADA TECH Specs.
        int Choice = getMenuChoice(4);

        if (Choice == 1) {
            addOneHour();
        }

        if (Choice == 2) {
            addOneMinute();
        }

        if (Choice == 3) {
            addOneSecond();
        }

        if (Choice == 4) {
            return;
        }
    }
}
// int main with both object variables to access classes
int main() {
    displayClocks(hours, minutes, seconds);
    mainMenu();
}
// I ran into (1>MSVCRT.lib(exe_main.obj) : error LNK2001: unresolved external symbol main)
//https://learn.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk2001?view=msvc-170
//I looked up what was the issue and removed the class and private identifier for the cpp file and actually print and create an executable file.
//