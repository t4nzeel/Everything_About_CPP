#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    string s="race a car";
    string s1="";
    for(char c : s){                   //Removes special characters.
        if(isalnum(c))  s1+=tolower(c);
    }
    string s2=s1;
    reverse(s1.begin(),s1.end());
    if(s2==s1){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not";
    }
}