#include<iostream>
#include<vector>
using namespace std;
void helper(vector<int>&nums,int idx,vector<int>&curr,vector<vector<int>>&ans){
    if(idx==nums.size()){
        ans.push_back(curr);
        return;
    }
    helper(nums,idx+1,curr,ans);
    curr.push_back(nums[idx]);
    helper(nums,idx+1,curr,ans);
    curr.pop_back();
}
vector<vector<int>> subsets(vector<int>&nums){
    vector<vector<int>>ans;
    vector<int>curr;
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