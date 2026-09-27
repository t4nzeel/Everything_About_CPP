#include<bits/stdc++.h>
using namespace std;
bool checkValidString(string s){
    int mn=0,mx=0;
    for(char c:s){
        if(c=='('){
            mn++;
            mx++;
        }
        else if(c==')'){
            mn--;
            mx--;
        }
        else{
            mn--;
            mx++;
        }
        if(mn<0)mn=0;
        if(mx<0)return false;
    }
    return (mn == 0);
}
int main(){
    string s;
    cin>>s;
    if(checkValidString(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}