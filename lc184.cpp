#include<bits/stdc++.h>
using namespace  std;
int minFallingPathSum(vector<vector<int>>& matrix){
    int n=matrix.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0]=matrix[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0)dp[i][j]=matrix[i][j]+min(dp[i-1][j+1],dp[i-1][j]);
            else if(j==n-1)dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            else dp[i][j]=matrix[i][j]+min(dp[i-1][j+1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return *min_element(dp[n-1].begin(),dp[n-1].end());
}
int main(){
    vector<vector<int>>v={{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(v)<<endl;
}