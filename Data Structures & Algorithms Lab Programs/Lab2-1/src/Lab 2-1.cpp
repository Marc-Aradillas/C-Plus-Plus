//============================================================================
// Name        : Lab2-1.cpp
// Author      : Marc Aradillas
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 2-1 Up to Speed in C++, Part 2
// Reference: https://www.youtube.com/watch?v=opvTByzx6g0
//============================================================================
#include <algorithm>
#include <iostream>
#include <time.h>

// FIXME (1): Reference the CSVParser library
// included the header file that was in the ZIP Folder. - Aradillas
#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

struct Bid {
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.title << " | " << bid.amount << " | " << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<Bid> loadBids(string csvPath) { // defined a vector data structure - Aradillas
	// FIXME (2): Define a vector data structure to hold a collection of bids.
	//

    vector<Bid> bids; //set the type as vector and variable at bids. - Aradillas

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

	// loop to read rows of a CSV file
	for (unsigned int i = 0; i < file.rowCount(); i++) { //changed the int type to unsinged per error for int types - Aradillas
        // FIXME (3): create a data structure to hold data from each row and add to vector
		Bid bid; // created the Bid structure and set local variable to for the for loop. - Aradillas
		bid.title = file[1][0]; //accessing file structure by row count and iterating for specific element in the vector. - Aradillas
		bid.fund = file[i][8]; //in this line of code per the csv file funds are located in row 8. -Aradillas
		bid.amount = strToDouble(file[i][4], '$'); // took (strToDouble) from below and passed the value to retrieve an amount that is a double type from the csv file - Aradillas

		// test/debug code to iterate and cout resutls.
		cout << "Title: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;
		// push_back method learned from Zybooks to use for the defined vector. - Aradillas
		// *Appends a new element having refValue* - Aradillas
		bids.push_back(bid);

    }
    return bids;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
    }

    // FIXME (4): Define a vector to hold all the bids
    vector<Bid> theBids; // vector with identifier theBids to hold all elements or bids for the load bids option. - Aradillas

    // FIXME (7a): Define a timer variable
    clock_t ticks; // Utilized the primer document to add the clock_t ticks code. - Aradillas

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        	cout << "Not currently implemented." << endl;

            break;
        case 2:
            // FIXME (7b): Initialize a timer variable before loading bids
        	ticks = clock(); // added line of code derived from the primer document provided in resources - Aradillas

            // FIXME (5): Complete the method call to load the bids
        	theBids = loadBids(csvPath); // assigned theBids to loadBids(csvPath) and completed the method call to pull the values from the csv file "eBid_Monthly_Sales_Dec_2016.csv" - Aradillas


            // FIXME (7c): Calculate elapsed time and display result
        	ticks = clock() - ticks; // added line of code derived from he primer document provided in the resources - Aradillas
        	// below is from the primer document as well.
        	cout << "time: " << ticks << " milliseconds" << endl;
        	cout << "time: " << ticks*1.0/CLOCKS_PER_SEC << " seconds" << endl;

            break;
        case 3:
            // FIXME (6): Loop and display the bids read
        	// input my variable and used .size and indentifier.at(i) to print elements of vector corresponding to assignment instructions - Aradillas
            for (unsigned int i = 0; i < theBids.size(); ++i) { // changed type to unsigned dur to error received from error list after compiling - Aradillas
            	displayBid(theBids.at(i));
            }
            cout << endl;

            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
