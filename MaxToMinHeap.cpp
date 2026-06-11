#include<iostream>
#include<vector>
using namespace std;
void Swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Heapify(int idx,vector<int>&nums){
    int li=2*idx+1;
    int ri=2*idx+2;
    int lar=idx;
    if(li<nums.size() && nums[li]>nums[lar]) lar=li;
    if(ri<nums.size() && nums[ri]>nums[lar]) lar=ri;
    if(lar!=idx){
        Swap(&nums[lar],&nums[idx]);
        Heapify(lar,nums);
    }
}
vector<int> minToMaxHeap(vector<int> nums){
    Heapify(0,nums);
    return nums;
}
int main(){
    vector<int>v={10, 20, 30, 21, 23};
    vector<int>v1=minToMaxHeap(v);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
}