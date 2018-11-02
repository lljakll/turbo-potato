#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

// Function to create newNode in a linkedlist
Node *newNode(int key)
{
	struct Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

//This program merges by inserting each node from list 2 into the tail of list 1
void merge(Node *list1, Node *list2)
{
	Node *ptr1 = list1;
	Node *ptr2 = list2;

	while (1)
	{
		if (ptr2 == NULL)
			break;

		if (ptr1->next == NULL)
		{
			ptr1->next = ptr2;
			

			while (list2 != NULL)
				list2 = list2->next;

			break;
		}

		list2 = list2->next;

		ptr2->next = ptr1->next;
		ptr1->next = ptr2;

		ptr2 = list2;
		ptr1 = (ptr1->next)->next;

	}


}

// A utility function to print linked list
void printList(Node *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
}

int main()
{
	Node *head1 = newNode(1);
	head1->next = newNode(3);
	head1->next->next = newNode(5);

	// 1->3->5 LinkedList created

	Node *head2 = newNode(0);
	head2->next = newNode(2);
	head2->next->next = newNode(4);

	// 0->2->4 LinkedList created

	merge(head1, head2);

	cout << "Merged List: ";
	printList(head1);
	cout << endl;
	system("pause");
	return 0;
}
