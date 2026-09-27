#include<bits/stdc++.h>
using namespace std;
int maxScore(vector<int>&v, int k){
    int ls=0,rs=0,mxs=0;
    for(int i=0;i<k;i++)ls+=v[i];
    mxs=ls;
    int r=v.size()-1;
    for(int i=k-1;i>=0;i--){
        ls-=v[i];
        rs+=v[r];
        mxs=max(mxs,ls+rs);
        r--;
    }
    return mxs;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<maxScore(v,k)<<endl;
}