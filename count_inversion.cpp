#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int> &v,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            cnt+=(mid-left+1);
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
    return cnt;
}
int mS(vector<int>&v,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mS(v,low,mid);
    cnt+=mS(v,mid+1,high);
    cnt+=merge(v,low,mid,high);
    return cnt;
}
int mergeSort(vector<int>&v,int n){
    return mS(v,0,n-1);
}
int main(){
    int s,x;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v1;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v1.push_back(x);
    }
    int c=mergeSort(v1,s);
    cout<<c;
}