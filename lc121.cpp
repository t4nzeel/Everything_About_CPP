#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>&v){
    int mx=0;
    for(int i=0;i<v.size();i++){
        if(i>mx)return false;
        mx=max(mx,i+v[i]);
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    if(canJump(v))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}