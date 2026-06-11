#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int r,c,x,n;
    cout<<"Enter the no. of rows & coulmns respectively : ";
    cin>>n;
    vector<vector<int>>m(n,vector<int>(n));
    vector<vector<int>>m1(n,vector<int>(n));
    c=n-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<" ";
            cin>>x;
            m[i][j]=x;
        }
    }
    /*for(int i=0;i<n;i++){
        r=n-1;
        for(int j=n-1;j>=0;j--){
            m1[r][c]=m[i][j];
            r=r-1;
        }
        c=c-1;
    }*/
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        swap(m[i][j],m[j][i]);
    }
   }
   for(int i=0;i<n;i++){
    reverse(m[i].begin(),m[i].end());
   }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}