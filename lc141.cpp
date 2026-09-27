#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool detect(int src,vector<vector<int>>&adj,vector<int>vis){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]=1;
                q.push({adjNode,node});
            }
            else if(parent!=adjNode)return true;
        }
    }
    return false;
}
bool detect_cylce(int V,vector<vector<int>>&adj){
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){                                                 
            if(detect(i,adj,vis))return true;
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
    if(detect_cylce(n,adj))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}