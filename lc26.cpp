#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int s,x;
    cout<<"ENter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    unordered_map<int,int>mp;
    int sum=0,maxi=0;
    for(int i=0;i<s;i++){
        sum+=v[i];
        if(sum==0){maxi=i+1;}
        else{
            if(mp.find(sum)!=mp.end()) {maxi=max(maxi,i-mp[sum]);}
            else {mp[sum]=i;}
        }
    }
    cout<<maxi;
    return 0;
}