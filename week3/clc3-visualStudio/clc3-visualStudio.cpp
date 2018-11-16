//In your group, propose one hash function for the numbers in the data on page 577 (the number is the key – index in the hash table array – and the name and number are the data). Define a hash table with 11 entries, and describe a linear method for handling collisions between indexes when inserting data in the table. Demonstrate that the hashing function works and collisions are handled, by storing and retrieving data from the hash table using the key as the position of a data item in the table.
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class HashedItem {
private:
	static const int tableSize = 11;

	// Data store for the Hash Table
	struct data {
		string number;
		string name;
	};

	data* HashTable[tableSize];

public:
	// Constructor
	HashedItem() {
		for (int i = 0; i < tableSize; i++) {
			HashTable[i] = new data;
			HashTable[i]->number = "";
			HashTable[i]->name = "";
		}
	}
	// Search the table by number.  Grabs the hash and checks the number.
	// if not a match, linearly moves until it's found.
	string FindByNumber(string number) {
		int index = Hash(number);
		int iter = index;
		int i = 1;

		// if hash is number, return name
		if (HashTable[iter]->number == number) {
			return HashTable[iter]->name;
		}
		else {
			while (i > -1) {
				cout << endl << "Checking index + " << i << " for " << number;
				// Check subsequent elements for the number
				if (HashTable[iter + i]->number == number) {
					return HashTable[iter + i]->name;
				}
				else {
					i++;
				}
				// if tableSize is reached wrap it to beginning
				if (iter + i == tableSize) {
					iter = 0;
					i = 0;
				}
				// if we have checked the entire table.  exit loop "not found"
				else if (iter + i == index) {
					i = -1;
				}
			}
		}
		return "No Entry";
	}

	// iterate through the table and output it.
	void PrintTable() {
		cout << endl << endl;
		for (int i = 0; i < tableSize; i++) {
			if (HashTable[i]->number != "") {
				cout << i << ": " << HashTable[i]->number << ": " << HashTable[i]->name << endl;
			}
		}
	}

	int Hash(string number) {
		int index = 0;
		// Hash: Add the total ASCII value of each number in the phone number 
		// multiply by 7, then mod by the tableSize
		for (int i = 0; i < number.length(); i++) {
			if (number[i] != '-') {
				index = index + (int)number[i];
			}
		}
		index = abs((index * 7) % tableSize); // hash function
		return index;
	}

	// Checks hashed element.  If full, move linearly to find an empty bucket.
	bool AddItem(string number, string name) {
		int index = Hash(number);
		int iter = 0;
		int orig = index;

		cout << endl << "Adding: " << name << " | " << number << " (hash = " << index << ") - ";
		// if empty, populate
		if (HashTable[index]->number == "") {
			cout << "Putting " << number << " in " << index;
			HashTable[index]->number = number;
			HashTable[index]->name = name;
		}
		else {
			cout << index << " is full, ";
			// cycle until empty bucket is found.
			while (index + iter < tableSize) {
				// when empty bucket is found, populate it
				if (HashTable[index + iter]->number == "") {
					cout << "Putting " << number << " in " << index + iter;
					HashTable[index + iter]->number = number;
					HashTable[index + iter]->name = name;
					iter = tableSize;
				}
				// loop if end has been reached
				if (index + iter == tableSize - 1) {
					index = 0;
					iter = -1;
				}
				// when we get back to the original hashed index, exit
				else if (index + iter == orig - 1) {
					cout << "Table is full";
					return false;
				}
				iter++;
			}
		}
	}
};

int main() {

	// Driver

	HashedItem testItem;

	// Populate the hashTable.  12 entries.  1 will not fit.
	testItem.AddItem("123-4567", "Adam");
	testItem.AddItem("345-5352", "Brenda");
	testItem.AddItem("983-7373", "Brendon");
	testItem.AddItem("987-1122", "Charles");
	testItem.AddItem("789-4563", "Jeremiah");
	testItem.AddItem("823-1573", "Katherine");
	testItem.AddItem("757-4532", "Patrick");
	testItem.AddItem("090-9383", "Raymond");
	testItem.AddItem("929-663", "Thorsten");
	testItem.AddItem("000-0021", "Jackie");
	testItem.AddItem("000-0111", "Michele");
	testItem.AddItem("000-0000", "BreakMe!");

	// Print the Table.
	testItem.PrintTable();

	// Find a number
	testItem.FindByNumber("987-1122");

	return 0;
}