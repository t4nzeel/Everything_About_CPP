#include<bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    vector<long long>nextRow(m,0);
    if(obstacleGrid[n-1][m-1]==0)nextRow[m-1]=1;
    else nextRow[m-1]=0;
    for(int i=m-2;i>=0;i--){
        if(obstacleGrid[n-1][i]==0)nextRow[i]=nextRow[i+1];
        else nextRow[i]=0;
    }
    for(int i=n-2;i>=0;i--){
        vector<long long>currentRow(m,0);
        for(int j=m-1;j>=0;j--){
            if(obstacleGrid[i][j]==1)currentRow[j]=0;
            else if(j==m-1)currentRow[j]=nextRow[j];
            else currentRow[j]=nextRow[j]+currentRow[j+1];
        }
        nextRow=currentRow;
    }
    return (int)nextRow[0];
}
int main(){
    vector<vector<int>>v={{0,1}};
    cout<<uniquePathsWithObstacles(v)<<endl;
}