#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void helper(vector<int>&nums,int idx,vector<int>&curr,vector<vector<int>>&ans){
    ans.push_back(curr);
    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1])continue;
        curr.push_back(nums[i]);
        helper(nums,i+1,curr,ans);
        curr.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>&nums){
    vector<vector<int>>ans;
    vector<int>curr;
    sort(nums.begin(),nums.end());
    helper(nums,0,curr,ans);
    return ans;
}
int main(){
    vector<int>v={1,2,2};
    vector<vector<int>>v1=subsets(v);
    for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v1[i].size(); j++) {
        cout << v1[i][j] << " ";
    }
    cout << endl;
}
}