#include<iostream>
#include<fstream>
using namespace std;
int main(){
    //string s="Hello Buddy.";
    //ofstream out("ofstream1.txt");
    //out<<s;
    //return 0;
    ofstream out;
    out.open("ofstream1.txt");
    out<<"Hello world!!!\n";
    out<<"CAn we be friends";
    out.close();
    return 0;
}