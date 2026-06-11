#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int row,int col,string s,vector<vector<int>>&grid,vector<string>&ans){
    int n=grid.size();
    int m=grid[0].size();
    if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0) return;
    if(row==n-1 && col==m-1){
        ans.push_back(s);
        return;
    }
    grid[row][col]=0;
    solve(row+1,col,s+'D',grid,ans);
    solve(row-1,col,s+'U',grid,ans);
    solve(row,col+1,s+'R',grid,ans);
    solve(row,col-1,s+'L',grid,ans);
    grid[row][col]=1;
}
vector<string>findPath(vector<vector<int>>&grid){
    vector<string>ans;
    solve(0,0,"",grid,ans);
    return ans;
}
int main(){
    vector<vector<int>>v={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>v1=findPath(v);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
}