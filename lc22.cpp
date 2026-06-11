#include<iostream>
#include<vector>
using namespace std;
vector<int>generateRow(int r){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int c=1;c<r;c++){
        ans=ans*(r-c);
        ans=ans/c;
        ansRow.push_back(ans);
    }
    return ansRow;
}
int main(){
    vector<vector<int>>v;
    int n;
    cout<<"Enter no. of rows : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        v.push_back(generateRow(i));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(i+1);j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<"\n";
    }
}