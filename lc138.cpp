#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector<vector<int>>& isConnected,vector<bool>&vis){
    vis[u]=true;
    int n=isConnected.size();
    for(int v=0;v<n;v++){
        if(isConnected[u][v]==1 && !vis[v])dfs(v,isConnected,vis);
    }
}
int findCircleNum(vector<vector<int>>& isConnected){
    int n=isConnected.size();
    vector<bool>vis(n,false);
    int ans=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,isConnected,vis);
            ans++;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> adj = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout<<findCircleNum(adj)<<endl;
}