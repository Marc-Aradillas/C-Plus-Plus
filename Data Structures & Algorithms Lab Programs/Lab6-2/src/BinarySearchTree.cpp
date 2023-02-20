//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Marc Aradillas
// Date		   : 12 February 2023
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
// References  : https://youtu.be/kq0LPPNwvzQ
//			   : ZyBooks Chapter 6
//			   : https://stackoverflow.com/questions/34361669/error-cannot-convert-stdbasic-stringchariterator-to-const-char-fo (str double error fix)
//
//============================================================================

#include <iostream>
#include <time.h>
#include <algorithm> // included algorithm for str double function error, would not call function (int remove(const char*)

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// FIXME (1): Internal structure for tree node
// BST (Binary Search Tree search algorithm)
struct Node {
	Bid bid;
	Node* left; // Node pointer for left
	Node* right; // Node pointer for right

	// Define constructor to initialize variables
	Node() {
		left = nullptr; // set left pointer null
		right = nullptr; // set right pointer null
	}

	// initialize with a given bid (makes syntax easier)
	Node(Bid aBid) : Node() { // passing in a bid, call this constructor node by giving it a bid it will first call the default constructor
		this->bid =  aBid;	  // with no arguments thus initializing left and right

	}

};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
// Binary Search Tree class Defined
class BinarySearchTree {

// Private & Public Methods
private:
	// Node Pointer to a Node called root
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    Node* removeNode(Node* node, string bidId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};

/**
 * Default constructor
 */
// 0848PM: Member root was not initialized
BinarySearchTree::BinarySearchTree() { // node within the BinarySearchTree class
    // initialize housekeeping variables
	root = nullptr; // member root was not initialized, added root set to null
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
	// calling recurssively inOrder
	this->inOrder(root); // start in the public tree class (starts at root and passes in)

}
/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    // FIXME (2a) Implement inserting a bid into the tree
	// Recursive call for insert method
	if (root == nullptr) { // if nothing in tree
		root = new Node(bid); // assign root to a new Node constructed from the bid to improve this we need a second constructor
	}
	// else condition if node is not null
	else {
			this ->addNode(root, bid); // addNode to pass bid
		}
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    // FIXME (4a) Implement removing a bid from the tree
	this->removeNode(root, bidId); // start at root and pass bidId
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    // FIXME (3) Implement searching the tree for a bid
	// we could while loop or recursive loop

	// start searching from the root
	Node* current = root; // root node the current node pointer (instance and assign to root

	// keep looping downwards until bottom reached or bid is found
	while (current != nullptr) { // we have something and determine we have a match
		// if current node matches, return it
		if (current->bid.bidId.compare(bidId) == 0) { // if comparison is a match
			return current->bid; // found match and returns bid
		}
		// if bid is smaller than current then traverse left
		if (bidId.compare(current->bid.bidId) < 0) { // left hand argument is smaller than 0
			current = current->left; // make left pointer new current node (while loop working down)
		}

		// larger than left hand argument
		else {
			current = current->right; // set current node tp the right
		}
	}

	Bid bid;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    // FIXME (2b) Implement inserting a bid into the tree
	// passing root node from top of tree (start)

	// if node is larger than the bid, add to left subtree
	if (node->bid.bidId.compare(bid.bidId) > 0) { // if new node is larger than root or curr
		if (node->left == nullptr) { // if left pointer is null
			node->left = new Node(bid); // construct new node and make left pointer
		}
		else { // if left node is not null; keep traversing down
			this->addNode(node->left, bid); // traverses anywhere down the tree to look at node
		}
	}

	//add to right subtree
	else {
		if (node->right == nullptr) { // if right pointer is null
			node->right = new Node(bid); // construct new node and make right pointer
		}
		else { // if right node is not null; keep traversing down
			this->addNode(node->right, bid); // traverses anywhere down the tree to look at node
		}
	}
}
void BinarySearchTree::inOrder(Node* node) {
	// in order from left to right calling the loop recursively (recursive method)
	if (node!= nullptr) {
		inOrder(node->left); // go down left

		cout << node->bid.bidId << ": "
			 << node->bid.title << " | "
			 << node->bid.amount << " | "
			 << node->bid.fund << endl;

		inOrder(node->right); // go down right
		//traverse entire tree in order
	}
}

Node* BinarySearchTree::removeNode(Node* node, string bidId) {
	// if this node is null then return (avoid crashing)
	if (node == nullptr) { // if node null
		return node; //return node
	}

	// recurse down left subtree
	if (bidId.compare(node->bid.bidId) < 0) { // if string bid given is smaller than the bid in current node, go down left side
		node->left = removeNode(node->left, bidId);
	}
	//recurse down right subtree
	else if (bidId.compare(node->bid.bidId) > 0) {
		node->right = removeNode(node->right, bidId); // recurse down right if larger
	}
	//
	else {
		// if leaf node with no children
		if (node->left == nullptr && node->right == nullptr) {
			delete node; // delete node
			node = nullptr;
		}
		// one child to the left
		else if (node->left != nullptr && node->right == nullptr) { // if child is on the left and not on the right
			Node* temp = node; // temporary node pointer
			node = node->left;
			delete temp;
		}
		// one child top the right
		else if (node->right != nullptr && node->left == nullptr) { // if child is on the left and not on the right
			Node* temp = node; // temporary node pointer
			node = node->right;
			delete temp;
		}
		// two children
		else {
			Node* temp = node->right; // Temporarily point to the right side and use temp to go left
			while (temp->left != nullptr) {
				temp = temp->left; // keep finding the left side to search for the minimum
			}
			node->bid = temp->bid; // held pinter and copy bid to it
			node->right = removeNode(node->right, temp->bid.bidId); // we get rid of the one to the right
		}
	}
	return node;
}
//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bst->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
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
int main(int argc, char* argv[]) { // main is set up to take zero, one, or two arguments

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1]; // if you pass one argument
        bidKey = "98109";
        break;
    case 3: // passing both
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default: // if no argument pass default ans use search key 98109
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bst = new BinarySearchTree();

            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bst);

            //cout << bst->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 4:
            bst->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

	return 0;
}
