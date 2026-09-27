#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void dijkstra(int n,vector<vector<pair<int,int>>>&adj,int s,int dist){
    vector<int>d(n,INT_MAX);
    vector<int>parent(n,-1);
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>>pq;
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dis>d[node])continue;
        for(auto edge:adj[node]){
            int nbr=edge.first;
            int wt=edge.second;
            if(dis+wt<d[nbr]){
                d[nbr]=dis+wt;
                parent[nbr]=node;
                pq.push({d[nbr],nbr});
            }
        }
    }
    if(d[dist]==INT_MAX){
        cout<<"No Path Exists!!!"<<endl;
        return;
    }
    vector<int>path;
    int node=dist;
    while(node!=-1){
        path.push_back(node);
        node=parent[node];
    }
    reverse(path.begin(),path.end());
    cout<<"Path : ";
    for(int x:path)cout<<x<<" ";
    cout<<endl;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int source, destination;
    cin >> source >> destination;
    dijkstra(n, adj, source, destination);
}