#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    string s,s1="";
    cout<<"Enter : ";
    cin>>s;
    unordered_map<char,int>m;
    for(char c:s) m[c]++;
    vector<pair<char,int>>v(m.begin(),m.end());  //To know that where this vector is pointing.
    sort(v.begin(),v.end(),[](auto &a,auto &b){
        return a.second>b.second;
    });
    for(auto &p :v){
        s1+=string(p.second,p.first);        //s1.append(p.second,p.first);
    }
    cout<<s1;
}