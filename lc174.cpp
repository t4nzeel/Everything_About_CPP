#include<bits/stdc++.h>
using namespace std;
int numRollsToTarget(int n, int k, int target){
    const int MOD = 1e9 + 7;
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int s=1;s<=target;s++){
            for(int f=1;f<=k && f<=s;f++){
                dp[i][s]=(dp[i][s]+dp[i-1][s-f])%MOD;
            }
        }
    }
    return dp[n][target];
}
int main(){
    cout<<numRollsToTarget(30,30,500)<<endl;
}