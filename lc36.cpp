#include<iostream>
#include<vector>
#include<climits>
using namespace std;
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
    int  n=v.size();
    int low=0,high=n-1,index=-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(v[low]<=v[high]){            //To save time if mid is at thr crossing point of rotation. 
            if(v[low]<ans){
                index=low;
                ans=v[low];
            }
            break;
        }
        if(v[low]<=v[mid]){
            if(v[low]<ans){
                index=low;
                ans=v[low];
            }
            low=mid+1;
        }
        else{
            high=mid-1;
            if(v[mid]<ans){
                index=mid;
                ans=v[mid];
            }
        }
    }
    cout<<index;
}