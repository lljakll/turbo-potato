// CST - 201
// 24 November 2018
// Green Group
// Jackie Adair
// Zachary Chambers
// Dylan Dorn
// This is our original work


#include "pch.h"
#include <iostream>
#include "BinaryTree.cpp"

using namespace std;



int main()
{
	// 6.14. 2. Write functions 
	// a.to count the number of nodes in a binary tree
	// b.to count the number of leaves
	// c.to count the number of right children
	// d.to find the height of the tree
	// e.to delete all leaves from a binary tree

	int TreeKeys[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
	BinaryTree myTree;

	cout << "The tree currently has: " << myTree.NodeCount() << " nodes." << endl;
	cout << "Adding 16 values to the tree..." << endl;
	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}
	cout << "The tree now has: " << myTree.NodeCount() << " nodes." << endl;

	cout << endl << endl;
	cout << "a. Count the number of nodes.  The tree currently has: " << myTree.NodeCount() << " nodes." << endl;
	cout << "b. Count the number of leaves.  The tree has: " << myTree.LeafCount() << " leaves." << endl;
	cout << "c. Count the number of right children.  The tree has: " << myTree.RightChildCount() << " right children." << endl;
	cout << "d. Find the height of the tree.  The height of the tree is: " << myTree.HeightOfTree() << endl;
	myTree.DeleteAllLeaves();
	cout << "e. Delete all leave from the tree.  There are now : " << myTree.LeafCount() << " nodes remaining." << endl;
	cout << endl;

	cin.get();
}

