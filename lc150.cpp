#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
    vis[row][col]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    int n=grid.size(),m=grid[0].size();
    for(int i=0;i<4;i++){
        int nr=row+dr[i];
        int nc=col+dc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m &&
            !vis[nr][nc] && grid[nr][nc]=='1')dfs(nr,nc,vis,grid);
    }
}
int numIslands(vector<vector<char>>& grid){
    int ans=0;
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] &&  grid[i][j]=='1'){
                ans++;
                dfs(i,j,vis,grid);
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<char>>v={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout<<numIslands(v)<<endl;
}