#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>>primsAlgo(vector<vector<pair<int,int>>>&adj,int n){
    vector<int>vis(n,0);
    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<tuple<int,int,int>>>pq;
    vector<tuple<int,int,int>>mst;
    pq.push({0,0,-1});
    while(!pq.empty()){
        auto[wt,node,par]=pq.top();
        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        if(par!=-1)mst.push_back({par,node,wt});
        for(auto[adjNode,edgeWt]:adj[node]){
            if(!vis[adjNode])pq.push({edgeWt,adjNode,node});
        }
    }
    return mst;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<tuple<int,int,int>>mst=primsAlgo(adj,n);
    for(auto[u,v,w]:mst){
        cout<<u<<" - "<<v<<" : "<<w<<endl;
    }
}