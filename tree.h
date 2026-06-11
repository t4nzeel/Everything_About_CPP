#ifndef TREE_H
#define TREE_H
#include <string>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val);
};
Node* buildTreeFromFile(ifstream &fin);
bool isSameTree(Node* t1, Node* t2);
#endif