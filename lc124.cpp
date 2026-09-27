#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>>insert(vector<vector<int>>&v,vector<int>&nv){
    int n=v.size();
    int i=0;
    vector<vector<int>>ans;
    while(i<n && nv[0]>v[i][1]){
        ans.push_back(v[i]);
        i++;
    }
    while(i<n &&  v[i][0] <= nv[1]){
        nv[0]=min(nv[0],v[i][0]);
        nv[1]=max(nv[1],v[i][1]);
        i++;
    }
    ans.push_back({nv[0],nv[1]});
    while(i<n){
        ans.push_back(v[i]);
        i++;
    }
    return ans;
}
int eraseOverlapIntervals(vector<vector<int>>&v){
    int ans=0;
    
}
int main(){}