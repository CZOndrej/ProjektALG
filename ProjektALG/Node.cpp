#include "Node.h"

Node::Node(int data)
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

void Node::SetLeft(int data)
{
	this->left = new Node(data);
}

void Node::SetRight(int data)
{
	this->right = new Node(data);
}

Node* Node::GetRight()
{
	return this->right;
}

Node* Node::GetLeft()
{
	return this->left;
}

int Node::GetData()
{
	return this->data;
}




