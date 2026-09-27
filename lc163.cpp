#include<bits/stdc++.h>
using namespace std;
vector<int>bellmanFord(int n,vector<vector<int>>&edges,int s){
    vector<int>dist(n,INT_MAX);
    dist[s]=0;
    for(int i=0;i<n-1;i++){
        for(auto edge:edges){
            int u=edge[0],v=edge[1],wt=edge[2];
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])dist[v]=wt+dist[u];
        }
    }
    //Check for -ve wt cycle.
    for(auto edge:edges){
        int u=edge[0],v=edge[1],wt=edge[2];
        if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
            cout<<"Contains -ve cycle"<<endl;
            return{};
        }
    }
    return dist;
}
int main(){
    int n=5;
    vector<vector<int>> edges ={{0, 1, 6},{0, 2, 7},{1, 2, 8},{1, 3, 5},{1, 4, -4},{2, 3, -3},{2, 4, 9},{3, 1, -2},{4, 0, 2},{4, 3, 7}};
    vector<int>ans=bellmanFord(n,edges,0);
    for(int i=0;i<n;i++){
        cout<<"Distance from "<<0<<" to "<<i<<" = "<<ans[i]<<endl;
    }
}