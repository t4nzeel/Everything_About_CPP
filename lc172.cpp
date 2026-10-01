#include<bits/stdc++.h>
using namespace std;
void dfs(int u,int parent,vector<vector<int>>&adj,vector<int>&time,vector<int>&low,vector<vector<int>>&bridges,int &timer){
    time[u]=low[u]=timer++;
    for(int v:adj[u]){
        if(v==parent)continue;
        if(time[v]==-1){
            dfs(v,u,adj,time,low,bridges,timer);
            low[u]=min(low[u],low[v]);
            if(low[v]>time[u])bridges.push_back({u,v});
        }
        else low[u]=min(low[u],time[v]);
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
    vector<vector<int>>adj(n);
    for(auto &e:connections){
        int u=e[0],v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>time(n,-1),low(n,-1);
    vector<vector<int>>bridges;
    int timer=0;
    dfs(0,-1,adj,time,low,bridges,timer);
    return bridges;
}
int main(){
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };
    vector<vector<int>> ans = criticalConnections(n, connections);
    for (auto &e : ans) {
        cout << "[" << e[0] << ", " << e[1] << "]\n";
    }
}