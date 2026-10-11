#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,int>dp;
int solve(long long n){
    if(n==0)return 0;
    if(dp.count(n))return dp[n];
    long long p=1;
    while(p<=n)p*=2;
    if(n==p/2)return dp[n]=1;
    int ans=1+solve(n-p/2);
    ans=min(ans,1+solve(p-n));
    return dp[n]=ans;
}
int minOperations(int n){
    return solve(n);
}
int main(){
    int n;
    cin>>n;
    cout<<minOperations(n)<<endl;
}