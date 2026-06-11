#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*bool is_Anagram(string s,string t){
    if(s.size()!=t.size()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}*/
bool is_Anagram(string s,string t){
    if(s.size()!=t.size()) return false;
    unordered_map<char,int>m;
    for(char c : s) m[c]++;
    for(char c : t){
        if(m.find(c)==m.end()) return false;
        m[c]--;
        if(m[c]==0)  m.erase(c);
    }
    return m.empty();
}
int main(){
    string s1,s2;
    cout<<"Enter ur strings : ";
    cin>>s1>>s2;
    if(is_Anagram(s1,s2)) cout<<"True.";
    else cout<<"False.";
}