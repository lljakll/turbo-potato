#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node *link;
};

struct Node *insert(struct Node *p, int n){
	struct Node *temp;
	/* if the existing list is empty then insert a new Node as the
	starting Node */
	if (p == NULL){
		p = (struct Node *) malloc(sizeof(struct Node)); /* creates new Node
														 data value passes
														 as parameter */

		if (p == NULL){
			printf("Error\n");
			exit(0);
		}
		p->data = n;
		p->link = p; /* makes the pointer pointing to itself because it
					 is a circular list*/
	}
	else{
		temp = p;
		/* traverses the existing list to get the pointer to the last Node of
		it */
		while (temp->link != p)
			temp = temp->link;
		temp->link = (struct Node *) malloc(sizeof(struct Node)); /*
																  creates new Node using
																  data value passes as
																  parameter and puts its
																  address in the link field
																  of last Node of the
																  existing list*/
		if (temp->link == NULL){
			printf("Error\n");
			exit(0);
		}
		temp = temp->link;
		temp->data = n;
		temp->link = p;
	}
	return (p);
}
void printlist(struct Node *p){
	struct Node *temp;
	temp = p;
	printf("The data values in the list are\n");
	if (p != NULL){
		do{
			printf("%d\t", temp->data);
			temp = temp->link;
		} while (temp != p);
	}
	else
		printf("The list is empty\n");
}
struct Node *merge(struct Node *p, struct Node *q){
	struct Node *temp = NULL;
	struct Node *r = NULL;
	r = p;
	temp = p;
	while (temp->link != p)
		temp = temp->link;
	temp->link = q;
	temp = q;
	while (temp->link != q)
		temp = temp->link;
	temp->link = r;
	return (r);
}

int main(){
	

	struct Node *start1 = NULL;
	struct Node *start2 = NULL;
	struct Node *start3 = NULL;

	//Populating each linked list with numbers through code (preset values instead of user input)
	start1 = insert(start1, 1);
	start1 = insert(start1, 3);
	start1 = insert(start1, 5);

	start2 = insert(start2, 2);
	start2 = insert(start2, 4);
	start2 = insert(start2, 6);
	start2 = insert(start2, 7);

	start3 = merge(start1, start2);
	cout << "The merged list is listed below \n" << endl;
	printlist(start3);
	getchar();
	return 0;
}
