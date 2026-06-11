#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int>v;
    int s,x,k;
    cout<<"ENter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter target : ";
    cin>>k;
    int xr=0,cnt=0;
    map<int,int>mpp;
    mpp[xr]++;
    for(int i=0;i<v.size();i++){
        xr=xr^v[i];
        int x=xr^k;
        cnt+=mpp[k];
        mpp[xr]++;
    }
    cout<<cnt;
}