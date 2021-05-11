
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Node.h"

using namespace std;

/**
* Načte soubor z předané cesty a navrací instanci vstupního datového proudu ifstream
*/
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
/**
* Zařadí nový uzel na příslušné místo ve stromu za předaný výchozí uzel. 
*/
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
/**
* Vytvoří Binární strom z předaného datového proudu
*/
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
/**
* Jako prametr přijímá kořenový uzel stromu a vrací počet pater binárního stromu
*/
int GetHeight(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else 
    {
        int leftHeight = GetHeight(node->GetLeft());
        int rightHeight = GetHeight(node->GetRight());

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
/**
* Navrací šířku patra stromu, jako parametr přebírá kořenový uzel a číslo příslušného patra
*/
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
/**
* Navrací šířku binárního stromu
*/
int GetMaxWidth(Node* root)
{
    int maxWidth = 0;
    for (int i = 1; i <= GetHeight(root); i++)
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
    Node* root = CreateTree(LoadFile("Tree1.txt"));

    cout << GetMaxWidth(root) << endl;
}


