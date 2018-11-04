#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node *head;

void addNodeAtPos(int data, int pos) {
	Node* prev = new Node();
	Node* curr = new Node();
	Node* newNode = new Node();
	newNode->data = data;

	int tempPos = 0;   // Traverses through the list

	curr = head;      // Initialize current to head;
	if (head != NULL) {
		while (curr->next != NULL && tempPos != pos) {
			prev = curr;
			curr = curr->next;
			tempPos++;
		}
		if (pos == 0) {
			cout << "Adding at Head! " << endl;
			head = newNode;
			newNode->next = curr;
		}
		else if (curr->next == NULL && pos == tempPos + 1) {
			cout << "Adding at Tail! " << endl;
			curr->next = newNode;
			newNode->next = NULL;
		}
		else if (pos > tempPos + 1)
			cout << " Position is out of bounds " << endl;
		//Position not valid

		else {
			prev->next = newNode;
			newNode->next = curr;
			cout << "Node added at position: " << pos << endl;
		}
	}
	else {
		head = newNode;
		newNode->next = NULL;
		cout << "Added at head as list is empty! " << endl;
	}
	Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void print() {
	Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	head = NULL; //empty linked list
	addNodeAtPos(7, 0);//List: 7     
	addNodeAtPos(5, 1); //List: 7,5   
	addNodeAtPos(8, 0); //List: 8,7,5 
	addNodeAtPos(6, 1); //List: 8,6,7,5      
	print();
	system("pause");
}
