#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <istream>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

//inserts new node to front of list
void push(struct Node** head_node, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); //allocates the node
	new_node->data = new_data;
	new_node->next = (*head_node);
	(*head_node) = new_node;
}

//deletes node at given position
void deleteNode(struct Node **head_node, int position) {
	
  //return if linked list is empty
	if (*head_node == NULL)
		return;

	//store head node
	struct Node* temp = *head_node;

	//in case head node needs removal
	if (position == 0) {
		*head_node = temp->next; //change head node
		free(temp);			 //frees old head node
		return;
	}

	//find node that comes before node that will be deleted
	for (int i = 0; temp != NULL && i<position - 1; i++)
		temp = temp->next;

	//what to return in # inputted is larger than # of nodes
	if (temp == NULL || temp->next == NULL)
		return;

	//node is deleted and pointer moves to next node
	struct Node *next = temp->next->next;

	free(temp->next); //frees the memory

	temp->next = next; //link of the deleted node to list is removed
}

//prints nodes in list
void printList(struct Node *node) {
	while (node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main() {

	//empty list at start
	struct Node* head = NULL;
	
	push(&head, 10);
	push(&head, 20);
	push(&head, 53);
	push(&head, 79);
	push(&head, 82);

	cout << "The Created List Is: " << endl;
	printList(head);
	deleteNode(&head, 3); //deletes node at specified position

	cout << "\nThe Linked List After Deletion at 3rd Position After Head: " << endl;
	printList(head);
	return 0;
}
