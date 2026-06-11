#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }
    for (int i = low; i <=high; i++){
        v[i]=temp[i-low];
    }
}
int count_pairs(vector<int>& v,int low,int mid,int high){
    int cnt=0;
    int right =mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && (long long)v[i]>(long long)2*v[right]) right++;
        cnt+=(right-(mid+1));
    }
    return cnt;
}
int mS(vector<int>&v,int low,int high){
    int cnt=0;
    if(low==high) return cnt;
    int mid=(low+high)/2;
    cnt+=mS(v,low,mid);
    cnt+=mS(v,mid+1,high);
    cnt+=count_pairs(v,low,mid,high);
    merge(v,low,mid,high);
    return cnt;
}
int mergeSort(vector<int>&v,int n){
    return mS(v,0,n-1);
}
int main(){
    vector<int>v1;
    int s,x;
    cout<<"Enter  size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v1.push_back(x);
    }
    int c=mergeSort(v1,s);
    cout<<c;
}