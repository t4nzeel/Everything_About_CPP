#include<iostream>
#include<vector>
using namespace std;
int main(){
    int r,c,x;
    cout<<"Enter the no. of rows & coulmns respectively : ";
    cin>>r>>c;
    vector<vector<int>>m(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<" ";
            cin>>x;
            m[i][j]=x;
        }
    }
    int col0=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]==0){
                m[i][0]=0;
                if(j!=0) {m[0][j]=0;}
                else {col0=0;}
            }
        }
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(m[i][j]!=0){
                if(m[i][0]==0 || m[0][j]==0) m[i][j]=0;
            }
        }
    }
    //If our 1st element is 0.
    if (m[0][0] == 0) {
        for (int j = 0; j < c; j++) {
            m[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < r; i++) {
            m[i][0] = 0;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}