#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"Enter : ";
    cin>>s;
    int len=s.size();
    for(int i=len-1;i>=0;i--){
        if((int)s[i]%2==1) {cout<<s.substr(0,i+1); break;}
    }
}