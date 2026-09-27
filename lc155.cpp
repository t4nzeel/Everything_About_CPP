#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void toposort(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        int v=it.first;
        if(!vis[v])toposort(v,adj,vis,st);
    }
    st.push(node);
}
vector<int>shortestPath(int n,int m,vector<vector<int>>edges){
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i])toposort(i,adj,vis,st);
    }
    vector<int>dist(n);
    for(int i=0;i<n;i++)dist[i]=1e9;
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt<dist[v])dist[v]=dist[node]+wt;
        }
    }
    return dist;
}
int main(){
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0]
            >> edges[i][1]
            >> edges[i][2];
    }
    vector<int> ans = shortestPath(n, m, edges);
    cout << "\nShortest distances from source vertex 0:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : " << ans[i] << '\n';
    }
}