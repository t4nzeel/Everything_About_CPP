#include<iostream>
#include<vector>
using namespace std;
bool check(int idx,vector<int>&nums){
    int n=nums.size();
    int li=2*idx+1;
    int ri=2*idx+2;
    if(li<n && nums[idx]>nums[li]) return false;
    if(ri<n && nums[idx]>nums[ri]) return false;
    bool leftOK=true,rightOK=true;
    if(li<n) leftOK=check(li,nums);
    if(ri<n) rightOK=check(ri,nums);
    return leftOK && rightOK;
}
bool isHeap(vector<int>&nums){
    return check(0,nums);
}
int main(){
    vector<int>v={10, 20, 30, 25, 15};
    if(isHeap(v)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}