#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& b){
    int f=0,t=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==5)f++;
        else if(b[i]==10){
            if(f){
                f--;
                t++;
            }
            else return false;
        }
        else{
            if(f && t){
                f--;
                t--;
            }
            else if(f>=3)f-=3;
            else return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    if(lemonadeChange(v))cout<<"Yes"<<endl;
    else  cout<<"No"<<endl;
}