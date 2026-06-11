#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int s,x,p=1;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    int pre=1,suff=1;
    int n=v.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre*=v[i];
        suff*=v[n-i-1];
        ans=max(ans,max(suff,pre));
    }
    cout<<ans;
}