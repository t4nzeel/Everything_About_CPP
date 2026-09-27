#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//BFS Kahn's algo Topo Sort
vector<int>topo_sortK(int V,vector<vector<int>>&adj){
    vector<int>inDegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it :adj[i])inDegree[it]++;
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0)q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto  it:adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0)q.push(it);
        }
    }
    return topo; 
}

//DFS Topo-Sort
void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto adjNode:adj[node]){
        if(!vis[adjNode])dfs(adjNode,vis,st,adj);
    }
    st.push(node);
}
vector<int>topo_sort(int V,vector<vector<int>>&adj){
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i])dfs(i,vis,st,adj);
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int V = 6;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    vector<int> ans = topo_sort(V, adj);
    cout << "Topological Order: ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}