#include<iostream>
#include<string>
#include<climits>
using namespace std;
int parentheses_depth(string s1){
    int d1=0;
    int d=0;
    for(char c : s1){
        if(c=='('){
            d1++;
            continue;
        }
        else if(c==')'){
            d=max(d,d1);
            d1--;
        }
    }
    return d;
}
int main(){
    string s;
    cout<<"Enter : ";
    cin>>s;
    cout<<parentheses_depth(s);
}