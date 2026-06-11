#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string s,s1,s2;
    ifstream tin("ifstream1.txt");
    tin>>s;
    cout<<s<<endl;
    getline(tin,s1);
    cout<<s1;
    getline(tin,s1);
    cout<<s1;
}