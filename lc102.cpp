#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& v){
    int n=v.size();
    vector<int>ans(n);
    stack<int>s;
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && v[s.top()]<=v[i%n])s.pop();
        if(i<n){
            ans[i]=s.empty() ? -1:v[s.top()];
        }
        s.push(i%n);
    }
    return ans;
}
int main(){
    int m;
    cin>>m;
    vector<int>v(m),ans;
    for(int &x:v)cin>>x;
    ans=nextGreaterElements(v);
    for(int &y:ans)cout<<y<<" ";
}