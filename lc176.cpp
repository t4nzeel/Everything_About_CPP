#include<bits/stdc++.h>
using namespace std;
int combinationSum4(vector<int>& nums, int target){
    vector<int>dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<nums.size();j++){
            if(nums[j]<=i){
                dp[i]=dp[i]+dp[i-nums[j]];
            }
        }
    }
    return  dp[target];
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<combinationSum4(v,4)<<endl;
}