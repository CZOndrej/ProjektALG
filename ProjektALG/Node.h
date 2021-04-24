#pragma once
class Node
{
private:
	int data;
	Node* left;
	Node* right;
public:
	Node(int data);
	void SetLeft(int data);
	void SetRight(int data);
	Node* GetRight();
	Node* GetLeft();
	int GetData();



};

