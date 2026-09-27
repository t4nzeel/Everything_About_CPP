#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
    int n=image.size();
    int m=image[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    int initial=image[sr][sc];
    if(initial==color)return image;
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vis[sr][sc]=1;
    image[sr][sc]=color;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
               && !vis[nrow][ncol] && image[nrow][ncol]==initial){
                vis[nrow][ncol]=1;
                image[nrow][ncol]=color;
                q.push({nrow,ncol});
            }
        }
    }
    return image;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>ans=floodFill(v,1,1,2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}