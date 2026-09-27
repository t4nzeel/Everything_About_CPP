#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
    vis[row][col]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,-1,0,1};
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<4;i++){
        int nr=row+dr[i];
        int nc=col+dc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m 
            && !vis[nr][nc] && grid[nr][nc]==1)
            dfs(nr,nc,vis,grid);
    }
}
int numEnclaves(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        if(!vis[0][j] && grid[0][j]==1)dfs(0,j,vis,grid);
        if(!vis[n-1][j] && grid[n-1][j]==1)dfs(n-1,j,vis,grid);
    }
    for(int i=0;i<n;i++){
        if(!vis[i][0] && grid[i][0]==1)dfs(i,0,vis,grid);
        if(!vis[i][m-1] && grid[i][m-1]==1)dfs(i,m-1,vis,grid);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1)ans++;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>v={{0,0,0,0},
                          {1,0,1,0},
                           {0,1,1,0},{0,0,0,0}};
    cout<<numEnclaves(v)<<endl;
}