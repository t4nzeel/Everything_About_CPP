#include<bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>>& roads){
    const long long MOD=1e9+7;
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto &edge:roads){
        int u=edge[0],v=edge[1],t=edge[2];
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    vector<long long>dist(n,LLONG_MAX);
    vector<long long>ways(n,0);
    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>>pq;
    dist[0]=0;
    ways[0]=1;
    pq.push({0,0});
    while(!pq.empty()){
        long long d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int nbr=it.first;
            long long wt=it.second;
            if(d+wt<dist[nbr]){
                dist[nbr]=d+wt;
                ways[nbr]=ways[node];
                pq.push({dist[nbr],nbr});
            }
            else if(d+wt==dist[nbr])ways[nbr]=(ways[nbr]+ways[node])%MOD;
        }
    }
    return ways[n-1];
}
int main(){
    vector<vector<int>>v={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout<<countPaths(7,v)<<endl;
}