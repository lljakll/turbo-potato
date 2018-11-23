

#include "pch.h"
#include <iostream>
#include "BinaryTree.cpp"

using namespace std;



int main()
{

	int TreeKeys[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
	BinaryTree myTree;

	cout << "The tree currently has: " << myTree.LeafCount() << " nodes." << endl;

	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "The tree currently has: " << myTree.LeafCount() << "nodes." << endl;

	cout << "Printing the Tree from smallest to largest: " << endl;
	myTree.PrintInOrder();
	cout << endl;
}

