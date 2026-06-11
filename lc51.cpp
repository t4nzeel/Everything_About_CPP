//For more efficient way see file lamda_comparator.
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;
pair<char,int> max_keyAndvalue(unordered_map<char,int>m1){
    char key;
    int maxval=INT_MIN;
    for(auto &p : m1){
        if(p.second>maxval){
            maxval=p.second;
            key=p.first;
        }
    }
    return {key,maxval};
}
int main(){
    string s,s1="";
    cout<<"Enter : ";
    cin>>s;
    unordered_map<char,int>m;
    for(char c : s){
        m[c]++;
    }
    while(!m.empty()){
        pair<char,int>p=max_keyAndvalue(m);
        for(int i=0;i<p.second;i++){
            s1+=p.first;
        }
        m.erase(p.first);
    }
    cout<<s1;
}