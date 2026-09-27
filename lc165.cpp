#include<bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
    vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    for(auto it:edges){
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }
    for(int i=0;i<n;i++)dist[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)dist[i][j]=min(dist[i][j],dist[k][j]+dist[i][k]);
            }
        }
    }
    int cntCity=n,cityNo=-1;
    for(int city=0;city<n;city++){
        int cnt=0;
        for(int adjCity=0;adjCity<n;adjCity++){
            if(dist[city][adjCity]<=distanceThreshold)cnt++;
        }
        if(cnt<=cntCity){
            cntCity=cnt;
            cityNo=city;
        }
    }
    return cityNo;
}
int main(){
    vector<vector<int>>v={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout<<findTheCity(4,v,4)<<endl;
}