#include<bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>&v, int k){
    /*int mx=0,l=0,r=0,z=0;
    int n=v.size();
    while(r<n){
        if(v[r]==0)z++;
        while(z>k){
            if(v[l]==0)z--;
            l++;
        }
        if(z<=k){
            int len=r-l+1;
            mx=max(mx,len);
        }
        r++;
    }
    return mx;*/
    int mx=0,l=0,r=0,z=0;
    int n=v.size();
    while(r<n){
        if(v[r]==0)z++;
        if(z>k){
            if(v[l]==0)z--;
            l++;
        }
        if(z<=k){
            int len=r-l+1;
            mx=max(mx,len);
        }
        r++;
    }
    return mx;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<longestOnes(v,k)<<endl;
}