#include<iostream>
#include<vector>
using namespace std;
int main(){
    int r,c,x;
    cout<<"Enter rows column : ";
    cin>>r>>c;
    vector<vector<int>>v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter value : ";
            cin>>v[i][j];
        }
    }
    int cnt_max=0;
    int index=-1;
    for(int i=0;i<r;i++){
        int cnt_ones=v[0].size()-(lower_bound(v[i].begin(),v[i].end(),1)-v[i].begin());
        if(cnt_ones>cnt_max){
            cnt_max=cnt_ones;
            index=i;
        }
    }
    cout<<index;
}