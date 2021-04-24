
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

void AddToTree(Node* root, int num)
{
    if (num > root->GetData())
    {
        if (root->GetRight() == nullptr)
        {
            root->SetRight(num);
        }
        else
        {
            AddToTree(root->GetRight(), num);
        }
    }
    else
    {
        if (root->GetLeft() == nullptr)
        {
            root->SetLeft(num);
        }
        else
        {
            AddToTree(root->GetLeft(), num);
        }
    }
}

void SumTree(Node* root, int * sum)
{
    *sum += root->GetData();
     if (root->GetLeft() != nullptr)
        SumTree(root->GetLeft(), sum);

     if (root->GetRight() != nullptr)
        SumTree(root->GetRight(), sum);

}   



int main()
{
    ifstream stream = LoadFile("Tree2.txt");

    Node * root = nullptr;
    int num;

    while (stream >> num)
    {
        if (root == nullptr)
        {
            root = new Node(num);
        }
        else
        {
            AddToTree(root, num);
        }
    }

    int* sum = new int;
    *sum = 0;

    int level = 0;

    SumTree(root, sum);
    cout << *sum << endl;


}


