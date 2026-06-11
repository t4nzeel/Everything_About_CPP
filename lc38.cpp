#include<iostream>
#include<vector>
using namespace std;
int peakindex(vector<int>& v1){
    int n=v1.size();
    if(n==1) return 0;
    if(v1[0]>v1[1]) return 0;
    if(v1[n-1]>v1[n-2]) return (n-1);
    int low =1,high=n-2;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(v1[mid]>v1[mid-1] && v1[mid]>v1[mid+1]) return mid;
        else if(v1[mid]>v1[mid-1]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    int s,x;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<peakindex(v);
}