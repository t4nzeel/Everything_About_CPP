#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"Enter : ";
    cin>>s;
    string s1="";
    int cnt=0;
    for(char c :s){
        if(c=='('){
            if(cnt>0) s1+=c;
            cnt++;
        }
        else{
            cnt--;
            if(cnt>0) s1+=c;
        }
    }
    cout<<s1;
}