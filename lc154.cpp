#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int>shortestPath(vector<vector<int>>&edges,int n ,int m,int src){
    vector<vector<int>>adj(n);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>dist(n);
    for(int i=0;i<n;i++)dist[i]=1e9;
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=1+dist[node];
                q.push(it);
            }
        }
    }
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        if(dist[i]!=1e9){
            ans[i]=dist[i];
        }
    }
    return ans;
}
int main(){
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++)cin >> edges[i][0] >> edges[i][1];
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<int> ans = shortestPath(edges, n, m, src);
    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; i++)cout << "Vertex " << i << " : " << ans[i] << '\n';
}