#include<bits/stdc++.h>
using namespace std;
vector<int> next_Greater_Element(vector<int>&num1,vector<int>&num2){
    stack<int>s;
    vector<int>ans;
    unordered_map<int,int>m;
    for(int x:num2){
        while(!s.empty() && x>s.top()){
            m[s.top()]=x;
            s.pop();
        }
        s.push(x);
    }
    while(!s.empty()){
        m[s.top()]=-1;
        s.pop();
    }
    for(int x:num1){
        ans.push_back(m[x]);
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n),V(m);
    for(int &x:v)cin>>x;
    for(int &x:V)cin>>x;
    vector<int>ans;
    ans=next_Greater_Element(v,V);
    for(int &x:ans)cout<<x<<" ";
    cout<<endl;
}