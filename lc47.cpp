//Do this using trie later.
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string>s1;
    int s;
    string s2,ans="";
    cout<<"Enter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter string : ";
        cin>>s2;
        s1.push_back(s2);
    }
    for(int i=0;i<s1[0].size();i++){
        char ch=s1[0][i];
        bool m=true;
        for(int j=1;j<s1.size();j++){
            if(s1[j].size()<i || ch!=s1[j][i]){
                m=false;
                break;
            }
        }
        if(m==false) break;
        else ans.push_back(ch);
    }
    cout<<ans;
}