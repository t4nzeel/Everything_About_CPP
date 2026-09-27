#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
    vector<int>par,size;
    public:
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)par[i]=i;
    }
    int findParent(int node){
        if(par[node]==node)return node;
        return par[node]=findParent(par[node]);
    }
    void unionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
int KruskalAlgo(int V,vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            int adjNode=it[0];
            int wt=it[1];
            int node=i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    int mstW=0;
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findParent(u)!=ds.findParent(v)){
            mstW+=wt;
            ds.unionBySize(u,v);
        }
    }
    return mstW;
}
int main(){
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> adj[V];
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int ans = KruskalAlgo(V, adj);
    cout << "Minimum cost of MST = " << ans << endl;
}