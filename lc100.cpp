#include<bits/stdc++.h>
using namespace std;
bool isValid(string S){
    stack<char>s;
    for(char c:S){
        if(c=='[' || c=='(' || c=='{'){
            s.push(c);
        }
        else{
            if(s.empty())return false;
            if((c=='}' && s.top()=='{') ||
               (c==']' && s.top()=='[') ||
               (c==')' && s.top()=='('))s.pop();
            else return false;
        }
    }
    return s.empty();
}
int main(){
    string S;
    cin>>S;
    if(isValid(S)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}