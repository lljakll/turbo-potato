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

// Helper functions
BinaryTree::node* BinaryTree::CreateLeafPrivate(int key)
{
	node* temp = new node;
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
int BinaryTree::MaxLevelPrivate(node* ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else
	{
		if (MaxLevelPrivate(ptr->left) > MaxLevelPrivate(ptr->right))
		{
			return 1 + MaxLevelPrivate(ptr->left);
		}
		else
		{
			return 1 + MaxLevelPrivate(ptr->right);
		}
	}
}

// Add leafs
void BinaryTree::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}
void BinaryTree::AddLeafPrivate(int key, node* ptr)
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
int BinaryTree::NodeCount()
{
	return NodeCountPrivate(root);
}
int BinaryTree::NodeCountPrivate(node* ptr)
{
	int count = 1;
	if (ptr == NULL)
	{
		return 0;
	}
	else
	{
		count += NodeCountPrivate(ptr->left);
		count += NodeCountPrivate(ptr->right);
	}
	return count;
}

// b.to count the number of leaves
int BinaryTree::LeafCount()
{
	return LeafCountPrivate(root);
}
int BinaryTree::LeafCountPrivate(node*ptr)
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
		return LeafCountPrivate(ptr->left) + LeafCountPrivate(ptr->right);
	}
}
// c.to count the number of right children
int BinaryTree::RightChildCount()
{
	return RightChildCountPrivate(root);
}
int BinaryTree::RightChildCountPrivate(node* ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	int numLeftNode = 0;
	int numRightNode = 0;
	if (ptr->left != NULL)
	{
		numLeftNode = RightChildCountPrivate(ptr->left);
	}
	if (ptr->right != NULL)
	{
		numRightNode = RightChildCountPrivate(ptr->right) + 1;
	}
	return numLeftNode + numRightNode;
}

// d.to find the height of the tree
int BinaryTree::HeightOfTree()
{
	return HeightOfTreePrivate(root);
}
int BinaryTree::HeightOfTreePrivate(node* ptr)
{
	int height = 0;
	height = MaxLevelPrivate(ptr) - 1;
	return height;
}

// e.to delete all leaves from a binary tree
void BinaryTree::DeleteAllLeaves()
{
	DeleteAllLeavesPrivate(root);
}
BinaryTree::node* BinaryTree::DeleteAllLeavesPrivate(node* ptr)
{
	if (ptr != NULL)
	{
		if (ptr->left == NULL && ptr->right == NULL)
		{
			free(ptr);
			return NULL;
		}
		else
		{
			ptr->left = DeleteAllLeavesPrivate(ptr->left);
			ptr->right = DeleteAllLeavesPrivate(ptr->right);
		}
	}
	return ptr;
}

// Print Nodes in order
void BinaryTree::PrintInOrder()
{
	PrintInOrderPrivate(root);
}
void BinaryTree::PrintInOrderPrivate(node* ptr)
{
	if (root != NULL)
	{
		if (ptr->left != NULL)
		{
			PrintInOrderPrivate(ptr->left);
		}
		std::cout << ptr->key << " ";
		if (ptr->right != NULL)
		{
			PrintInOrderPrivate(ptr->right);
		}
	}
	else
	{
		std::cout << "The Tree is empty.";
	}
}