#pragma once
class BinaryTree
{
private:

	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node *root;

	void AddLeafPrivate(int key, node* ptr);

public:
	        BinaryTree();
	node*   CreateLeaf(int key);
	void    AddLeaf(int key);
	int     MaxLevel(node* ptr);
	int     NodeCount(node* ptr);
	int     LeafCount(node* ptr);
	int     RightChildCount(node* ptr);


};

