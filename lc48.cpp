#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
bool contains_Value(unordered_map<char,char>m1,char value){
    for(auto &p : m1){
        if(p.second==value) return true;
    }
    return false;
}
bool is_Ismorphic(string s1,string t1){
    unordered_map<char,char>m;
    if(s1.size()!=t1.size()) return false;
    for(int i=0;i<s1.size();i++){
        char o=s1[i];
        char r=t1[i];
        if(!m.count(o)){
            if(!contains_Value(m,r)) m[o]=r;
            else return false;
        }
        else{
            char mc=m[o];
            if(mc!=r) return false;
        }
    }
    return true;
}
int main(){
    string s,t;
    cout<<"Enter ur strings respectivelu : ";
    cin>>s>>t;
    if(is_Ismorphic(s,t)) cout<<"Isomorphic.";
    else cout<<"Not Isomorphic.";
}