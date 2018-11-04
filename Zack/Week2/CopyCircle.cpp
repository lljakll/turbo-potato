// Connor_Circle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

struct item {
	int data;
	struct item *next;
};

class CLList {
private:
	item * head;
	item * tail;
public:
	CLList() {
		head = NULL;
		tail = NULL;
	}
	void createNode(int value) {
		// create a new list item using the passed value
		item *n = new item;
		n->data = value;
		n->next = NULL;

		// if head is null, tail must equal head: instantiate new list
		if (head == NULL) {
			head = n;
			tail = n;
			n = NULL;
		}

		// else, add to end, link to head, and update tail,
		else {
			n->next = head;
			tail->next = n;
			tail = n;
			
		}
	}

	void display() {
		// create an item to move through the list, head to tail
		item *pos = new item;
		pos = head;

		// while the current node exists, output the item's data and increment the node position.
		
		do {
			cout << pos->data << "\t" << endl;
			pos = pos->next;
		} while (pos != head);
	}

	void copyList(CLList list) {
		CLList *listP = new CLList;
		*listP = list;
		// create an item to move through the passed-in list, head to tail
		item *pos = new item;
		pos = listP->head;

		// while the current node exists, copy the item into the list and update position.
		do {
			this->createNode(pos->data);
			pos = pos->next;
		} while (pos != listP->head);
	}
};



int main() {

	CLList A, B;
	A.createNode(1);
	A.createNode(2);
	A.createNode(3);
	A.createNode(4);
	A.createNode(50);
	cout << "display A" << endl;
	A.display();
	cout << "copying A to B" << endl;
	B.copyList(A);
	cout << "display B" << endl;
	B.display();
	cout << "added node to B" << endl;
	B.createNode(60);
	cout << "display B" << endl;
	B.display();
	cout << "display A" << endl;
	A.display();
    return 0;
}
