#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream in;
    string s, s1;
    in.open("eof1.txt");
    //in>>s>>s1;
    //cout<<s<<s1;
    while (in.eof()==0)
    {
        getline(in,s);
        cout<<s<<endl;
    }
    return 0;
}