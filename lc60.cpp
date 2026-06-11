#include<iostream>
#include<vector>
using namespace std;
int find_MAX_index(vector<vector<int>>v2,int n1,int col){
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n1;i++){
        if(maxValue<v2[i][col]){
            maxValue=v2[i][col];
            index=i;
        }
    }
    return index;
}
vector<int> find_Peak(vector<vector<int>>v1){
    int n=v1.size();
    int m=v1[0].size();
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int maxRowIndex=find_MAX_index(v1,n,mid);
        int left= mid-1>=0 ? v1[maxRowIndex][mid-1]: -1;
        int right= mid+1<m ? v1[maxRowIndex][mid+1]: -1;
        if(v1[maxRowIndex][mid]>left && v1[maxRowIndex][mid]>right) return {maxRowIndex,mid};
        else if(v1[maxRowIndex][mid]<left) high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}
int main(){
    int r,c,x;
    cout<<"Enter row and column : ";
    cin>>r>>c;
    vector<vector<int>>v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter value : ";
            cin>>x;
            v[i][j]=x;
        }
    }
    vector<int>v0=find_Peak(v);
    cout<<v0[0]<<" , "<<v0[1];
}