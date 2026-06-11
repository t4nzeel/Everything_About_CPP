#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int s,x,t,mid;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter ur target : ";
    cin>>t;
    sort(v.begin(),v.end());
    int n=v.size();
    int ans=-1;
    int low=0,high=n-1;
    //Floor value.
    while(low<=high){
        mid=(low+high)/2;
        if(v[mid]<=t) {
            ans=v[mid];
            low=mid+1;
        } 
        else high=mid-1;
    }
    //Ceil value.
   while(low<=high){
    mid=(low+high)/2;
    if(v[mid]<t) low=mid+1;
    else{
        ans=v[mid];
        high=mid-1;
    }
   }
    cout<<ans;
}