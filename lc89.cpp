#include<iostream>
#include<vector>
using namespace std;
void Swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Heapify(int idx,vector<int>&nums,int n){
    int li=2*idx+1;
    int ri=2*idx+2;
    int lar=idx;
    if(li<n && nums[li]>nums[lar]) lar=li;
    if(ri<n && nums[ri]>nums[lar]) lar=ri;
    if(lar!=idx){
        Swap(&nums[lar],&nums[idx]);
        Heapify(lar,nums,n);
    }
}
int findKthLargest(vector<int> &nums,int k){
    int n = nums.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        Heapify(i, nums,n);
    }
    for(int  i=0;i<k-1;i++){
        Swap(&nums[0],&nums[n-1-i]);
        Heapify(0,nums,n-1-i);
    }
    return nums[0];
}
int main(){
    vector<int>v={2,1};
    int k=2;
    int v1=findKthLargest(v,k);
    cout<<v1<<endl;
}