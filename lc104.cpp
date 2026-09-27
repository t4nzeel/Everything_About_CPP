#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
using ll=long long;
int sumSubarrayMins(vector<int>&v){
    int n=v.size();
    vector<int>pse(n),nse(n);
    stack<int>s;
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
        ans=(ans+c)%MOD;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    int ans=sumSubarrayMins(v);
    cout<<ans<<endl;
}