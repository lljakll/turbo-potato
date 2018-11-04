#include "stdafx.h"
#include <iostream>
using namespace std;


struct item {
	int data;
	item *next;
};

class LinkedList {
private:
	item * head, *tail;
public:
	LinkedList() {
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

		// else, add to end and update tail
		else {
			tail->next = n;
			tail = n;
		}
	}
	
  void display() {
		// create an item to move through the list, head to tail
		item *pos = new item;
		pos = head;

		// while the current node exists, output the item's data and increment the node position.
		while (pos != NULL)
		{
			cout << pos->data << "\t" << endl;
			pos = pos->next;
		}
	}
	
  void copyList(LinkedList list) {
		LinkedList *listP = new LinkedList;
		*listP = list;
		// create an item to move through the passed-in list, head to tail
		item *pos = new item;
		pos = listP->head;

		// while the current node exists, copy the item into the list and update position.
		while (pos != NULL) {
			this->createNode(pos->data);
			pos = pos->next;
		}
	}
};

int main() {
	LinkedList listA, listB;
	listA.createNode(1);
	listA.createNode(2);
	listA.createNode(3);
	listA.createNode(4);
	listA.createNode(50);
	cout << "display A" << endl;
	listA.display();
	cout << "copying A to B" << endl;
	listB.copyList(listA);
	cout << "display B" << endl;
	listB.display();
	cout << "added node to B" << endl;
	listB.createNode(60);
	cout << "display B" << endl;
	listB.display();
	cout << "display A" << endl;
	listA.display();
	
	return 0;
};
