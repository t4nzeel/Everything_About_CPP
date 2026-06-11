#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;
int main()
{
    ifstream fin("tree_input.txt");
    ofstream fout("tree_output.txt");
    if(!fin)
    {
        cout<<"Input file not found\n";
        return 0;
    }
    Node* tree1 = buildTreeFromFile(fin);
    Node* tree2 = buildTreeFromFile(fin);
    if(isSameTree(tree1, tree2))
        fout<<"Trees are identical\n";
    else
        fout<<"Trees are not identical\n";
    fin.close();
    fout.close();
    return 0;
}