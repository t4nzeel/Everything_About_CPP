#include <iostream>
#include <fstream>
#include "tree.h"
Node::Node(int val)
{
    data = val;
    left = NULL;
    right = NULL;
}
Node* buildTreeFromFile(ifstream &fin)
{
    string path;
    int value;
    Node* root = NULL;
    while(fin >> path)
    {
        if(path == "END")
            break;
        fin >> value;
        if(path == "root")
        {
            root = new Node(value);
            continue;
        }
        Node* curr = root;
        for(int i = 0; i < path.length()-1; i++)
        {
            if(path[i] == 'L')
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(path.back() == 'L')
            curr->left = new Node(value);
        else
            curr->right = new Node(value);
    }
    return root;
}
bool isSameTree(Node* t1, Node* t2)
{
    if(t1 == NULL && t2 == NULL)
        return true;
    if(t1 == NULL || t2 == NULL)
        return false;
    if(t1->data != t2->data)
        return false;
    return isSameTree(t1->left, t2->left) &&
           isSameTree(t1->right, t2->right);
}