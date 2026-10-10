#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount){
    vector<int>dp(amount+1,1e9);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            if(coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return(dp[amount]<1e9 ? dp[amount]:-1);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<coinChange(v,11)<<endl;
}