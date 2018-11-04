#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

//insert node at beginning of list
void push(struct Node **head_node, int data) {
	//create new node, push old head node next to new head node
	struct Node *pointer =
		(struct Node *)malloc(sizeof(struct Node));
	pointer->data = data;
	pointer->next = *head_node;

	//make node next to the tail node as temp if list is not NULL
	if (*head_node != NULL) {
		//find node next to head and update it
		struct Node *temp = *head_node;
		while (temp->next != *head_node)
			temp = temp->next;
		temp->next = pointer;
	}
	else
		pointer->next = pointer;

	*head_node = pointer;
}

void printList(struct Node *head) {
	struct Node *temp = head;
	if (head != NULL) {
		do {
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);
	}
	cout << "\n" << endl;
}

//delete given node from list
void deleteNode(struct Node *head, int key) {
	if (head == NULL)
		return;

	//find wanted node
	struct Node *current = head, *prev = nullptr;
	while (current->data != key) {
		if (current->next == head) {
			cout << "Given node is not in the list" << endl;
		}

		prev = current;
		current = current->next;
	}

	//check if there is only one node in list
	if (current->next == head) {
		head = NULL;
		free(current);
		return;
	}

	//checks if node is the first node when there is more than one node in list
	if (current == head) {
		prev = head;
		while (prev->next != head)
			prev = prev->next;
		head = current->next;
		prev->next = head;
		free(current);
	}

	//checking if node is last in list
	else if (current->next == head) {
		prev->next = head;
		free(current);
	}
	else {
		prev->next = current->next;
		free(current);
	}
}

int main() {
  //initializing empty list
	struct Node *head = NULL;

	push(&head, 10);
	push(&head, 20);
	push(&head, 53);
	push(&head, 79);
	push(&head, 82);

	cout << "List Before Any Modification: " << endl;
	printList(head);

	deleteNode(head, 53);

	cout << "List After Deletion of Value 53: " << endl;
	printList(head);
}
