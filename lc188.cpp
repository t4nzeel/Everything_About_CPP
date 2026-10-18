#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<vector<int>>>dp;
int solve(int r1,int c1,int r2,vector<vector<int>>&grid){
    int c2=r1+c1-r2;
    if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)return -1e9;
    if(r1==n-1 && c1==n-1)return grid[r1][c1];
    if(dp[r1][c1][r2]!=INT_MIN)return dp[r1][c1][r2];
    int cherries=grid[r1][c1];
    if(r1!=r2 || c1!=c2)cherries+=grid[r2][c2];
    int a=solve(r1+1,c1,r2+1,grid);
    int b=solve(r1+1,c1,r2,grid);
    int c=solve(r1,c1+1,r2+1,grid);
    int d=solve(r1,c1+1,r2,grid);
    int best=max({a,b,c,d});
    if(best<0)return dp[r1][c1][r2]=-1e9;
    return dp[r1][c1][r2]=cherries+best;
}
int cherryPickup(vector<vector<int>>& grid){
    n=grid.size();
    dp.assign(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
    return max(0,solve(0,0,0,grid));
}
int main(){
    vector<vector<int>>v={{0,1,-1},{1,0,-1},{1,1,1}};
    cout<<cherryPickup(v)<<endl;
}