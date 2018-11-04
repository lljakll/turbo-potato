#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

//head_node = head, deleted node = del_node
void deleteNode(struct Node **head_node, struct Node *del_node) {
	if (*head_node == NULL || del_node == NULL)
		return;

	//if trying to delete head node
	if (*head_node == del_node)
		*head_node = del_node->next;

	//move to next node if deleted node is not at end of list
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;

	//change previous node if deleted node is not first node in list
	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;

	//free memory used by del_node
	free(del_node);
	return;
}

//inserting node at beginning of list
void push(struct Node** head_node, int new_data) {
	//allocating node
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	//input new data
	new_node->data = new_data;

	//previous node is NULL since adding at beginning
	new_node->prev = NULL;

	//link old list off new node
	new_node->next = (*head_node);

	//change node previous to head node to become new node
	if ((*head_node) != NULL)
		(*head_node)->prev = new_node;

	//head pointer to new node
	(*head_node) = new_node;
}

void printList(struct Node *node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main() {
	
	//empty list
	struct Node* head = NULL;

	//making list
	push(&head, 10);
	push(&head, 20);
	push(&head, 53);
	push(&head, 79);
	push(&head, 32);

	cout << "Original Doubly Linked List Is: " << endl;
	printList(head);

	deleteNode(&head, head); //deleting first node
	deleteNode(&head, head->next); //deleting middle node
								  
	cout << "\nLinked List After Deletion at Head and Middle of List: " << endl;
	printList(head);
}
