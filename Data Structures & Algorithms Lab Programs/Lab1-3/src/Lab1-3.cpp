//============================================================================
// Name : Lab1-3.cpp
// Author : Marc Aradillas
// Class : CS-260-T3299 Data Structures and Algorithms 23EW3
// Date: 08 January, 2022
// Project: 1-3 Up-to-Speed Activity: C++, Part One
// Version : 1.0
// Copyright : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
// References: https://youtu.be/3cAYYXA0iQ8
//============================================================================
#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

double strToDouble(string str, char ch);

// FIXME (1): Define a data structure to hold bid information together as a single unit of storage.

//Defined data structure; used Type struct
struct Bid {
	// set string variables for referenced data structure type; Bid
	string title;
	string fund;
	string vehicle;
	double amount;
	// used bid elements from referenced video example
};

// FIXME (4): Display the bid values passed in data structure
/**
* Display the bid information
*
* @param ?type? data structure containing the bid info
*/

//Bid values set for displayBid() method;
void displayBid(Bid bid) {
	cout << "Title: " << bid.title << endl;
	cout << "Fund: " << bid.fund << endl;
	cout << "Vehicle: " << bid.vehicle << endl;
	cout << "Bid Amount: " << bid.amount << endl;
	//Utilized member access operator (dot notation)
	//to assign variables to struct Bid variables; assigns each corresponding data member
	return;
}

// FIXME (3): Store input values in data structure
/**
* Prompt user for bid information
*
* @return data structure containing the bid info
*/

//Stored input values in data structure
Bid getBid() {
	Bid bidOne;
	//used dot notation to assign to referenced variables
	cout << "Enter title: ";
	cin.ignore();
	getline(cin, bidOne.title);

	cout << "Enter fund: ";
	cin >> bidOne.fund;

	cout << "Enter vehicle: ";
	cin.ignore();
	getline(cin, bidOne.vehicle);

	cout << "Enter amount: ";
	cin.ignore();
	string strAmount;
	getline(cin, strAmount);
	bidOne.amount = strToDouble(strAmount, '$');

	//populates return value of method
	return bidOne;
}

/**
* Simple C function to convert a string to a double
* after stripping out unwanted char
*
* credit: http://stackoverflow.com/a/24875936
*
* @param ch The character to strip out
*/


//
double strToDouble(string str, char ch) {
	str.erase(remove(str.begin(), str.end(), ch), str.end());
	return atof(str.c_str());
}

/**
* The one and only main() method
*/
int main() {

	// FIXME (2): Declare instance of data structure to hold bid information

	//Defined data structure to hold bid information together as a single file
	Bid theBid;

	// loop to display menu until exit chosen
	int choice = 0;
	while (choice != 9) {
		cout << "Menu:" << endl;
		cout << " 1. Enter Bid" << endl;
		cout << " 2. Display Bid" << endl;
		cout << " 9. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		// FIXME (5): Complete the method calls then test the program

		//Completed method calls by replacing ?variable? with type/variable
		//set above (bid TheBid).
		switch (choice) {
			case 1:
				theBid = getBid();
				break;
			case 2:
				displayBid(theBid);
				break;
		}
	}

	cout << "Good bye." << endl;

	return 0;
}

//program was run multiple times, however i tried to utilize the debug feature and was unable
//to remedy the bug which made the output loop. I created a text file with " set new-console on
//and I had the same result. I did install IDE & JAVA on my personal machine.

//Program tested and code operates as intended
