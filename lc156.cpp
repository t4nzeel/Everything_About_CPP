#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int>dijkstra(int n,vector<vector<pair<int,int>>>&adj,int s){
    vector<int>dist(n,INT_MAX);
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>>pq;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int d=pq.top().first;
        int n=pq.top().second;
        pq.pop();
        if(d>dist[n])continue;
        for(auto it:adj[n]){
            int nbr=it.first;
            int wt=it.second;
            if(d+wt<dist[nbr]){
                dist[nbr]=d+wt;
                pq.push({dist[nbr],nbr});
            }
        }
    }
    return dist;
}


vector<int>dijkstra2(int n,vector<vector<pair<int,int>>>&adj,int s){
    vector<int>dist(n,INT_MAX);
    set<pair<int,int>>st;
    dist[s]=0;
    st.insert({0,s});
    while(!st.empty()){
        auto it=st.begin();
        int d=it->first;
        int n=it->second;
        st.erase(it);
        for(auto edge:adj[n]){
            int nbr=edge.first;
            int wt=edge.second;
            if(d+wt<dist[nbr]){
                if(dist[nbr]!=INT_MAX)st.erase({dist[nbr],nbr});
            }
            dist[nbr]=wt+d;
            st.insert({dist[nbr],nbr});
        }
    }
    return dist;
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
    int source;
    cin >> source;
    vector<int> dist = dijkstra2(n, adj, source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
}