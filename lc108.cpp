#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int largestRectangleArea(vector<int>&v){
    /*int n=v.size();
    stack<int>s;
    vector<int>pse(n),nse(n);
    for(int i=0;i<n;i++){
        while(!s.empty() && v[s.top()]>=v[i])s.pop();
        pse[i]=s.empty() ? -1:s.top();
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && v[s.top()]>=v[i])s.pop();
        nse[i]=s.empty() ? n : s.top();
        s.push(i);
    }
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,v[i]*(nse[i]-pse[i]-1));
    }
    return mx;*/
    int n=v.size();
    stack<int>s;
    int mx=0;
    for(int i=0;i<=n;i++){
        int cur=(i==n ? 0 : v[i]);
        while(!s.empty() && v[s.top()]>cur){
            int h=v[s.top()];
            s.pop();
            int r=i;
            int l=s.empty() ? -1 : s.top();
            int w=r-l-1;
            mx=max(mx,h*w);
        }
        s.push(i);
    }
    return mx;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<largestRectangleArea(v)<<endl;
}