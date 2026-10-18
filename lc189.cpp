#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<vector<int>>>dp;
int solve(int i,int j1,int j2,vector<vector<int>>& grid){
    if(j1<0 || j1>=n || j2<0 || j2>=n)return -1e9;
    if(i==m-1){
        if(j1==j2)return grid[i][j1];
        return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int cherries=grid[i][j1];
    if(j1!=j2)cherries+=grid[i][j2];
    int best=0;
    for(int d1=-1;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            best=max(best,solve(i+1,j1+d1,j2+d2,grid));
        }
    }
    return dp[i][j1][j2]=cherries+best;
}
int cherryPickup(vector<vector<int>>& grid){
    m=grid.size();
    n=grid[0].size();
    dp.assign(m,vector<vector<int>>(n,vector<int>(n,-1)));
    return solve(0,0,n-1,grid);
}
int main(){
    vector<vector<int>>v={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout<<cherryPickup(v)<<endl;
}