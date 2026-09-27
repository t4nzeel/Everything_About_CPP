#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool dfs(int node,int col,vector<vector<int>>&graph,vector<int>&color){
    color[node]=col;
    for(int  neighbour:graph[node]){
        if(color[neighbour]==-1){
            if(!dfs(neighbour,1-col,graph,color))return false;
        }
        else if(color[neighbour]==color[node])return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int>color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!dfs(i,0,graph,color))return false;
        }
    }
    return true;
}
int main(){
    vector<vector<int>>v={{1,3},{0,2},{1,3},{0,2}};
    if(isBipartite(v))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}