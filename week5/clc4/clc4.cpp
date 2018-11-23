

#include "pch.h"
#include <iostream>

using namespace std;

class BinaryTree1
{
private:

	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node *root;


public:

	BinaryTree1()
	{
		root = NULL;
	}

	node* CreateLeaf(int key)
	{
		node* temp = new node;
		temp->key = key;
		temp->left = NULL;
		temp->right = NULL;
	}

	void 

	int NodeCount(struct node* node)
	{
		int count = 1;
		if (node == NULL)
			return 0;
		else
		{
			count += NodeCount(node->left);
			count += NodeCount(node->right);
		}
		return count;
	}

	int LeavesCount(struct node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		if (node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		else
			return LeavesCount(node->left) + LeavesCount(node->right);
	}

	int RightChildCount(struct node* node)
	{
		if (node == NULL)
			return 0;
		int numLeftNode = 0;
		int numRightNode = 0;
		if (node->left != NULL)
			numLeftNode = RightChildCount(node->left);
		if (node->right != NULL)
			numRightNode = RightChildCount(node->right) + 1;
		return numLeftNode + numRightNode;
	}

	int maxLevel(struct node* node)
	{
		if (node == NULL)
			return 0;
		else
		{
			if (maxLevel(node->left) > maxLevel(node->right))
			{
				return 1 + maxLevel(node->left);
			}
			else
				return 1 + maxLevel(node->right);
		}
	}

	int heightTree(struct node* node)
	{
		int height = 0;
		height = maxLevel(node) - 1;
		return height;
	}

	struct node* deleteLeaves(struct node* node)
	{
		if (node != NULL)
		{
			if (node->left == NULL && node->right == NULL)
			{
				free(node);
				return NULL;
			}
			else
			{
				node->left = deleteLeaves(node->left);
				node->right = deleteLeaves(node->right);
			}
		}
		return node;
	}
};

int main()
{
	struct node *tree = CreateNode(21);
	tree->left = CreateNode(12);
	tree->right = CreateNode(13);
	tree->left->left = CreateNode(19);
	tree->left->right = CreateNode(25);
	tree->right->left = CreateNode(36);
	tree->right->right = CreateNode(47);

	cout << "Number of leaves in bin tree: " << LeavesCount(tree) << endl;
	cout << "Number of nodes in bin Tree: " << NodeCount(tree) << endl;
	cout << "Number of right children in bin tree: " << RightChildCount(tree) << endl;
	cout << "Height of bin tree: " << heightTree(tree) << endl;
	deleteLeaves(tree);
	cout << "Number of nodes now: " << NodeCount(tree) << endl;
	getchar();
}

