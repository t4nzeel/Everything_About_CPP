#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool rotate_string(string s1,string g1){
    /*if(s1.size()!=g1.size()) return false;
    if(s1.empty() && g1.empty())return true;
    size_t it=g1.find(s1[0]);
    if (it == string::npos) return false;
    it=s1.size()-it;
    reverse(s1.begin(),s1.begin()+it);
    reverse(s1.begin()+it,s1.end());
    reverse(s1.begin(),s1.end());
    if(s1==g1) return true;
    else return false;*/
    if(s1.size()!=g1.size()) return false;
    if((s1+s1).find(g1)!=string::npos) return true;
    else return false;
}
int main(){
    string s,goal;
    cout<<"Enter ur strings : ";
    cin>>s>>goal;
    if(rotate_string(s,goal)) cout<<"True.";
    else cout<<"False.";
}