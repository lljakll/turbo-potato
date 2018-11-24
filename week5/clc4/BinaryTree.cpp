// 6.14. 2. Write functions 
// a.to count the number of nodes in a binary tree
// b.to count the number of leaves
// c.to count the number of right children
// d.to find the height of the tree
// e.to delete all leaves from a binary tree


#include "pch.h"
#include <iostream>
#include <cstdlib>

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

	// Helper functions
	node* CreateLeafPrivate(int key)
	{ // Returns a new node with the passed key as the nodes key
		node* temp = new node;
		temp->key = key;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}
	int DeepestLevelPrivate(node* ptr)
	{ // helper function to recursively find the deepest level so HeightOfTree function can determin its value
		if (ptr == NULL)
		{
			return 0;
		}
		else
		{
			if (DeepestLevelPrivate(ptr->left) > DeepestLevelPrivate(ptr->right)) // check if left i deeper than right
			{
				return 1 + DeepestLevelPrivate(ptr->left); // if yes, keep recursively check left again and add 1
			}
			else
			{
				return 1 + DeepestLevelPrivate(ptr->right); // if no, go down the right adding 1
			}
		}
	}

	// Add leafs
	void AddLeafPrivate(int key, node* ptr)
	{
		if (root == NULL)
		{
			root = CreateLeafPrivate(key);
		}
		else if (key < ptr->key)
		{
			if (ptr->left != NULL)
			{
				AddLeafPrivate(key, ptr->left);
			}
			else
			{
				ptr->left = CreateLeafPrivate(key);
			}
		}
		else if (key > ptr->key)
		{
			if (ptr->right != NULL)
			{
				AddLeafPrivate(key, ptr->right);
			}
			else
			{
				ptr->right = CreateLeafPrivate(key);
			}
		}
	}

	// a.to count the number of nodes in a binary tree
	int NodeCountPrivate(node* ptr)
	{
		int count = 1;
		if (ptr == NULL)
		{
			return 0;
		}
		else
		{
			count += NodeCountPrivate(ptr->left); // increment count recursively
			count += NodeCountPrivate(ptr->right);
		}
		return count;
	}

	// b.to count the number of leaves
	int LeafCountPrivate(node*ptr)
	{
		if (ptr == NULL)
		{
			return 0;
		}
		if (ptr->left == NULL && ptr->right == NULL) // check for no children
		{
			return 1;
		}
		else
		{
			return LeafCountPrivate(ptr->left) + LeafCountPrivate(ptr->right); // add recursively counted null lefts and rights
		}
	}

	// c.to count the number of right children
	int RightChildCountPrivate(node* ptr)
	{
		if (ptr == NULL)
		{
			return 0;
		}
		int numLeftNode = 0;
		int numRightNode = 0;
		if (ptr->left != NULL) // check right children on the left branches
		{
			numLeftNode = RightChildCountPrivate(ptr->left); // increment by 1 recursively
		}
		if (ptr->right != NULL) // check right children of the right branches
		{
			numRightNode = RightChildCountPrivate(ptr->right) + 1; // increment by 1 recursively
		}
		return numLeftNode + numRightNode;  // add them together
	}

	// d.to find the height of the tree
	int HeightOfTreePrivate(node* ptr)
	{
		int height = 0;
		height = DeepestLevelPrivate(ptr) - 1;
		return height;
	}

	// e.to delete all leaves from a binary tree
	node* DeleteAllLeavesPrivate(node* ptr)
	{
		if (ptr != NULL)
		{
			if (ptr->left == NULL && ptr->right == NULL)  // if is a leaf
			{
				free(ptr); // delete it
				return NULL;
			}
			else
			{
				ptr->left = DeleteAllLeavesPrivate(ptr->left); // recursively move down the left sides
				ptr->right = DeleteAllLeavesPrivate(ptr->right); // recursively move down the right sides
			}
		}
		return ptr;
	}

public:
	BinaryTree()
	{
		root = NULL;
	}
	void AddLeaf(int key)
	{
		AddLeafPrivate(key, root);
	}
	int NodeCount()
	{
		return NodeCountPrivate(root);
	}
	int LeafCount()
	{
		return LeafCountPrivate(root);
	}
	int RightChildCount()
	{
		return RightChildCountPrivate(root);
	}
	int HeightOfTree()
	{
		return HeightOfTreePrivate(root);
	}
	void DeleteAllLeaves()
	{
		DeleteAllLeavesPrivate(root);
	}

};