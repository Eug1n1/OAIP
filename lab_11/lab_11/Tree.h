#pragma once

#include <iostream>
#include <fstream>
using namespace std;

struct  Node
{
	int key;
	int count;
	Node* left;
	Node* right;
};

struct Tree
{
	int countR = 0;
	Node* node = nullptr;
	int counter;
	void AddNode(int k);
	void PrintTree(Node* temp, int l);
	void Delete(int k);
	bool Balance(Node* temp);
	void DirectBypass(Node* temp);
	void ReverseBypass(Node* temp);
	void countRight(Node* temp);
};
