#pragma once
#include<string>
#include "./headers/d5RBtreeNode.h"
class d5RBTree
{
private:
	d5RBtreeNode* root;

	

	//balance the tree upon inserting a new node
	void insertion_balance(d5RBtreeNode* node);

	//rotates the tree at node to the left
	void rotateLeft(d5RBtreeNode* node);

	//rotates the tree at node to the right
	void rotateRight(d5RBtreeNode* node);

	//prepares the tree to remove the node
	void prepareForRemoval(d5RBtreeNode* node);

	//called from removeNode
	void BSTRemove(d5RBtreeNode* node);

	//called from BSTRemove only
	void rightSuccessorRemove(d5RBtreeNode* rightSuccessor);

	//called from insertNode
	void customTupleInsert(d5RBtreeNode* newNode);


	/*
	* tryCases are helpers for prepareForRemoval()
	*/

	bool tryCase1(d5RBtreeNode* node);
	bool tryCase2(d5RBtreeNode* node, d5RBtreeNode* sibling);
	bool tryCase3(d5RBtreeNode* node, d5RBtreeNode* sibling);
	bool tryCase4(d5RBtreeNode* node, d5RBtreeNode* sibling);
	bool tryCase5(d5RBtreeNode* node, d5RBtreeNode* sibling);
	bool tryCase6(d5RBtreeNode* node, d5RBtreeNode* sibling);

	


public:
	
	//constructor
	d5RBTree();

	//gets the size of the tree O(n)
	int size();

	//insert a new node into the tree
	void insertNode(d5RBtreeNode* newNode);

	//true if the node is null or black
	bool isNullOrBlack(d5RBtreeNode* node);

	//true if node isnt null and is red
	bool isNotNullAndRed(d5RBtreeNode* node);

	//another remove
	bool remove(std::tuple<__int64, __int64, __int64> key);

	//called from remove
	void removeNode(d5RBtreeNode* node);

	//searches the tree for the tuple
	d5RBtreeNode* search(std::tuple<__int64, __int64, __int64> key);

	void inOrderPrint();

	void inOrderTraversePrint(d5RBtreeNode* root);

	__int64 part1Filter(__int64 key);

	d5RBtreeNode* part1Search(__int64 key);

};

