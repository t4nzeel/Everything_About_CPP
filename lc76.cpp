#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void helper(vector<int>&nums,int idx,int target,vector<int>&curr,vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;
        curr.push_back(nums[i]);
        helper(nums,i+1,target-nums[i],curr,ans);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>&candidates, int target){
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>ans;
    vector<int>curr;
    helper(candidates,0,target,curr,ans);
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