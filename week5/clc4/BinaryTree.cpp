// 6.14. 2. Write functions 
// a.to count the number of nodes in a binary tree
// b.to count the number of leaves
// c.to count the number of right children
// d.to find the height of the tree
// e.to delete all leaves from a binary tree


#include "pch.h"
#include "BinaryTree.h"

#include <iostream>



BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::node* BinaryTree::CreateLeaf(int key)
{
	node* temp = new node;
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
}

void BinaryTree::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BinaryTree::AddLeafPrivate(int key, node* ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < ptr->key)
	{
		if (ptr->left != NULL)
		{
			AddLeafPrivate(key, ptr->left);
		}
		else
		{
			ptr->left = CreateLeaf(key);
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
			ptr->right = CreateLeaf(key);
		}
	}
}

int BinaryTree::MaxLevel(node* ptr)
{
	if (ptr)
}

// a.to count the number of nodes in a binary tree
int BinaryTree::NodeCount(node* ptr)
{
	int count = 1;
	if (ptr == NULL)
	{
		return 0;
	}
	else
	{
		count += NodeCount(ptr->left);
		count += NodeCount(ptr->right);
	}
	return count;
}

// b.to count the number of leaves
int BinaryTree::LeafCount(node*ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	if (ptr->left == NULL && ptr->right == NULL)
	{
		return 1;
	}
	else
	{
		return LeafCount(ptr->left) + LeafCount(ptr->right);
	}
}

// c.to count the number of right children
int BinaryTree::RightChildCount(node* ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	int numLeftNode = 0;
	int numRightNode = 0;
	if (ptr->left != NULL)
	{
		numLeftNode = RightChildCount(ptr->left);
	}
	if (ptr->right != NULL)
	{
		numRightNode = RightChildCount(ptr->right) + 1;
	}
	return numLeftNode + numRightNode;
}

// d.to find the height of the tree