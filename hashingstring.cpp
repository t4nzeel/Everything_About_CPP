#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter ur string : ";
    cin>>s;
    int hash[256]={0};    //256 is  the size to take all the characters in reach.
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;           //Auto converts s[i] into ASCII value.
    }
    int q;
    cout<<"Enter ur queries : ";
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<c<<" appeared "<<hash[c]<<" times."<<endl;
    }
    return 0;
}