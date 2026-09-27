#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll sumSubarrayMins(vector<int>&v){
    int n=v.size();
    vector<ll>pse(n),nse(n);
    stack<ll>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && v[s.top()]>v[i])s.pop();
        pse[i]=s.empty() ? i+1 : i-s.top();
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && v[s.top()]>=v[i])s.pop();
        nse[i]=s.empty() ? n-i : s.top()-i;
        s.push(i);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll c=1LL*v[i]*pse[i]*nse[i];
        ans=ans+c;
    }
    return ans;
}
ll sumSubarrayMaxs(vector<int>&v){
    int n=v.size();
    vector<ll>pge(n),nge(n);
    stack<ll>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && v[s.top()]<=v[i])s.pop();
        pge[i]=s.empty() ? i+1 : i-s.top();
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && v[s.top()]<v[i])s.pop();
        nge[i]=s.empty() ? n-i : s.top()-i;
        s.push(i);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll c=1LL*v[i]*pge[i]*nge[i];
        ans=ans+c;
    }
    return ans;
}
ll subArrayRanges(vector<int>&v){
    ll smn=sumSubarrayMins(v);
    ll smx=sumSubarrayMaxs(v);
    return smx-smn;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<subArrayRanges(v)<<endl;    
}