#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int s,x,mid,t;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter ur target : ";
    cin>>t;
    int n=v.size();
    int low=0,high=n-1;
    while(low<=high){
        mid=low+((high-low)/2);
        if(v[mid]==t)  {cout<<"True"; break;}
        //Left sort check
        if(v[low]<=v[mid]){
            if(v[low]<=t && t<=v[mid]) high=mid-1;
            else low=mid+1;
        }
        //Right sort check
        else{
            if(v[mid]<=t && t<=v[high]) low=mid+1;
            else high=mid-1;
        }
    }
}