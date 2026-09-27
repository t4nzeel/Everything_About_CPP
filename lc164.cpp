#include<bits/stdc++.h>
using namespace std;
void floydWarshal(vector<vector<int>>&matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1)matrix[i][j]=INT_MAX;
            if(i==j)matrix[i][j]=0;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX)matrix[i][j]=min(matrix[i][j],matrix[k][j]+matrix[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(matrix[i][i]<0){
            cout<<"Contains -ve cylce"<<endl;
            return;
        }
    }
}
int main(){
    vector<vector<int>> dist = {
        {1,   6,   7,   -1, -1},
        {-1, 2,   8,   5,   -4},
        {-1, -1, 3,  -3,   9},
        {-1, -2,  -1, 4,   -1},
        {2,   -1, -1, 7,   5}
    };
    floydWarshal(dist);
    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}