#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s,s1="",s2="";
    cout<<"Enter : ";
    getline(cin,s);
    int len=s.size();
    for(int i=len-1;i>=0;i--){
        if(s.at(i)==' ' && i<len-1 && s.at(i+1)==' ') continue; //Get rid of extra space(s) in between.
        if(s.at(i)!=' '){
            s1+=s.at(i);
        }
        else if(s.at(i)==' '){
            reverse(s1.begin(),s1.end());
            if (!s2.empty()) s2 += " "; // removes trailing spaces.
            s2=s2+s1;
            s1="";
        }
    }
    if(!s1.empty()){
        reverse(s1.begin(),s1.end());
        if (!s2.empty()) s2 += " ";
        s2+=s1;
    }
    cout<<s2;
}