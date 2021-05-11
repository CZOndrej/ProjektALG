#include "Node.h"

Node::Node(int data)
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}
/**
* Vytvoří nový ukazatel na levý uzel
*/
void Node::SetLeft(int data)
{
	this->left = new Node(data);
}
/**
* Vytvoří nový ukazatel na pravý uzel
*/
void Node::SetRight(int data)
{
	this->right = new Node(data);
}
/**
* Vrací ukazatel na pravý uzel
*/
Node* Node::GetRight()
{
	return this->right;
}
/**
* Vrací ukazatel na levý uzel
*/
Node* Node::GetLeft()
{
	return this->left;
}
/**
* Vrací číselnou hodnotu uzlu
*/
int Node::GetData()
{
	return this->data;
}




