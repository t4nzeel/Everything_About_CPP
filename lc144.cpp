#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>>dist(n,vector<int>(m,-1));
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]==-1){
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    return dist;
}
int main(){
    vector<vector<int>>v={{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>>ans=updateMatrix(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}