#include<iostream>
#include<vector>
using namespace std;
void helper(vector<int>&nums,int idx,int s1,int target,vector<int>&curr,vector<vector<int>>&ans){
    if(s1==target){
        ans.push_back(curr);
        return;
    }
    if(s1>target || idx==nums.size()){
        return;
    }
    curr.push_back(nums[idx]);
    helper(nums,idx,s1+nums[idx],target,curr,ans);
    curr.pop_back();
    helper(nums,idx+1,s1,target,curr,ans);
}
vector<vector<int>> combinationSum(vector<int>&candidates, int target){
    vector<vector<int>>ans;
    vector<int>curr;
    helper(candidates,0,0,target,curr,ans);
    return ans;
}
int main(){
    vector<int>v={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>>v1=combinationSum(v,target);
    for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v1[i].size(); j++) {
        cout << v1[i][j] << " ";
    }
    cout << endl;
}
}