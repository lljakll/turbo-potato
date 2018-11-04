// Connor_Double.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct item {
public:
	int data;
	item *next;
	item *prev;
};

class DoubleList {
private:
	item * head, *tail;
public:
	DoubleList() {
		head = NULL;
		tail = NULL;
	}

	void link(item * a, item * b) {
		a->next = b;
		b->prev = a;
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
			// move tail to end
			item *oldTail = tail;
			oldTail->next = n;
			tail = n;
			tail->prev = oldTail;
			cout << "item added" << endl;
			if (n->prev == NULL && n->next == NULL) {
				cout << "no prev or next" << endl;
				cout << n->data << endl;
			}
			else if (n->prev == NULL) {
				cout << "no prev" << endl;
				cout << n->data << "-->" << n->next->data << endl;
			}
			else if (n->next == NULL) {
				cout << "no next" << endl;
				cout << n->prev->data << "<--" << n->data << endl;
			}
			else {
				cout << "fully linked" << endl;
				cout << n->prev->data << "<--" << n->data << "-->" << n->next->data << endl;
			}
		}

	}
	void display()
	{
		// create an item to move through the list, head to tail
		item *pos = new item;
		pos = head;

		// while the current node exists, output the item's data and increment the node position.
		while (pos != NULL)
		{
			if (pos->prev == NULL && pos->next == NULL)
				cout << pos->data << endl;
			if (pos->prev == NULL)
				cout << pos->data << "-->" << pos->next->data << endl;
			else if (pos->next == NULL)
				cout << pos->prev->data << "<--" << pos->data << endl;
			else
				cout << pos->prev->data << "<--" << pos->data << "-->" << pos->next->data << endl;
			pos = pos->next;
		}
	}
	void copyList(DoubleList list) {
		DoubleList *listP = new DoubleList;
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

int main()
{
	DoubleList listA, listB;
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
};
