#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//undirected graph
bool dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto adjNode:adj[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode,node,vis,adj)==true)return true;
        }
        else if(adjNode!=parent)return true;
    }
    return false;
}

//directed graph
bool dfs_Direc(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs_Direc(it,adj,vis,pathVis))return true;
        }
        else if(pathVis[it])return true;
    }
    pathVis[node]=0;
    return false;
}

bool detect_cycle(int V,vector<vector<int>>&adj){
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)==true)return true;
        }
    }
    return false;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(detect_cycle(n,adj))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}