
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Node.h"

using namespace std;


ifstream LoadFile(string path)
{
    ifstream fileStream;
    fileStream.open(path);

    if (!fileStream)
    {
        cerr << "Unable to open file";
        exit(1);
    }

    return fileStream;
}

void AddNode(Node* node, int num)
{
    if (num > node->GetData())
    {
        if (node->GetRight() == nullptr)
        {
            node->SetRight(num);
        }
        else
        {
            AddNode(node->GetRight(), num);
        }
    }
    else
    {
        if (node->GetLeft() == nullptr)
        {
            node->SetLeft(num);
        }
        else
        {
            AddNode(node->GetLeft(), num);
        }
    }
}

Node* CreateTree(ifstream stream)
{
    Node* root = nullptr;
    int num;

    while (stream >> num)
    {
        if (root == nullptr)
        {
            root = new Node(num);
        }
        else
        {
            AddNode(root, num);
        }
    }
    return root;
}

int GetSum(Node* root)
{
    if (root->GetLeft() != nullptr)
    {
        return GetSum(root->GetLeft()) + root->GetData();
    }
    if (root->GetRight() != nullptr)
    {
        return GetSum(root->GetRight()) + root->GetData();
    }
    if ((root->GetRight() == nullptr && root->GetLeft() == nullptr))
    {
        return root->GetData();
    }
}

int GetHeigth(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else 
    {
        int leftHeight = GetHeigth(node->GetLeft());
        int rightHeight = GetHeigth(node->GetRight());

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
           return rightHeight + 1;
        }
    }
}

int GetLevelWidth(Node* root, int level)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (level == 1)
    {
        return 1;
    }
    else if (level > 1)
    {
        return GetLevelWidth(root->GetLeft(), level - 1) + GetLevelWidth(root->GetRight(), level - 1);
    }
}

int GetMaxWidth(Node* root)
{
    int maxWidth = 0;
    for (int i = 1; i <= GetHeigth(root); i++)
    {
        if (maxWidth < GetLevelWidth(root, i))
        {
            maxWidth = GetLevelWidth(root, i);
        }
    }
    return maxWidth;
}

int main()
{
    Node* root = CreateTree(LoadFile("Tree2.txt"));

    

    cout << GetSum(root) << endl;
}


