#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    queue<pair<int,pair<int,int>>>q;
    int n=grid.size();
    int m=grid[0].size();
    if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[0][0]=1;
    q.push({1,{0,0}});
    int dr[]={-1,-1,-1,0,1,1,1,0};
    int dc[]={-1,0,1,1,1,0,-1,-1};
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.second;
        if(r==n-1 && c==m-1)return dis;
        for(int i=0;i<8;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n &&
               nc>=0 && nc<m &&
               grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                dist[nr][nc]=1+dis;
                q.push({1+dis,{nr,nc}});
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>>v={{0,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(v)<<endl;
}