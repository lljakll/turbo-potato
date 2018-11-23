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

	void    AddLeafPrivate(int key, node* ptr);
	void    PrintInOrderPrivate(node* ptr);
	int     MaxLevelPrivate(node* ptr);
	int     NodeCountPrivate(node* ptr);
	int     LeafCountPrivate(node* ptr);
	int     RightChildCountPrivate(node* ptr);
	int     HeightOfTreePrivate(node* ptr);
	node*   DeleteAllLeavesPrivate(node* ptr);
	node*   CreateLeafPrivate(int key);
public:
	        BinaryTree();

	void    AddLeaf(int key);
	void    PrintInOrder();

	int     NodeCount();
	int     LeafCount();
	int     RightChildCount();
	int     HeightOfTree();
	void    DeleteAllLeaves();


};

