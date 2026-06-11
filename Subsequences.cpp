#include<iostream>
#include<vector>
using namespace std;
void helper(vector<int>&nums,vector<int>&curr,int idx,int s1,int k,int &ans){
    if(idx==nums.size()){
        if(s1==k){
            ans++;
        }
        return;
    }
    curr.push_back(nums[idx]);
    s1+=nums[idx];
    helper(nums,curr,idx+1,s1,k,ans);
    curr.pop_back();
    s1-=nums[idx];
    helper(nums,curr,idx+1,s1,k,ans);
}
int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    int ans=0;
    vector<int>curr;
    helper(nums,curr,0,0,k,ans);
    return ans;
}
int main(){
    vector<int>v={4,2,10,5,1,3};
    int k=5;
    int count=countSubsequenceWithTargetSum(v,k);
    cout<<count;
}