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
void mS(vector<int>&v,int low,int high){
    if(low==high) return;
    int mid=(low+high)/2;
    mS(v,low,mid);
    mS(v,mid+1,high);
    merge(v,low,mid,high);
}
void mergeSort(vector<int>&v,int n){
    mS(v,0,n-1);
}
int main(){
    int s,x;
    vector<int>v1;
    cout<<"Enter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v1.push_back(x);
    }
    int l=0;
    int m=(s+1)/2;
    int h=s-1;
    mS(v1,l,h);
    merge(v1,l,m,h);
    mergeSort(v1,s);
    for (int i = 0; i < s; i++)
    {
        cout<<v1.at(i)<<" ";
    }
    

}