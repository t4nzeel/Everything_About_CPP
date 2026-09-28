#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void dfs1(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(int next:adj[node]){
        if(!vis[next])dfs1(next,adj,vis,st);
    }
    st.push(node);
}
void dfs2(int node,vector<vector<int>>&transpose,vector<int>&vis){
    vis[node]=1;
    cout<<node<<" ";
    for(int next:transpose[node]){
        if(!vis[next])dfs2(next,transpose,vis);
    }
}
int main(){
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    vector<int> vis(V, 0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i])dfs1(i,adj,vis,st);
    }
    vector<vector<int>>transpose(V);
    for(int u=0;u<V;u++){
        for(int v:adj[u])transpose[v].push_back(u);
    }
    fill(vis.begin(),vis.end(),0);
    cout<<"SCCs:\n";
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            dfs2(node,transpose,vis);
            cout<<endl;
        }
    }
}