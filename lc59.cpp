#include<iostream>
#include<vector>
using namespace std;
/*bool binary_search(vector<vector<int>>&v2,int t1,int i1){
    int n=v2[0].size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(v2[i1][mid]==t1) return true;
        if(v2[i1][mid]>t1) high=mid-1;
        else low=mid+1;
    }
    return false;
}
bool search_ele(vector<vector<int>>&v1,int target){
    int c1=v1[0].size();
    for(int i=0;i<v1.size();i++){
        if(v1[i][0]<=target && target<=v1[i][c1-1]){
            if(binary_search(v1,target,i)) return true;
        }
    }
    return false;
}*/
bool search_ele(vector<vector<int>>&v1,int target){
    int n=v1.size(),m=v1[0].size();
    int r=0,c=m-1;
    while(r<n && c>=0){
        if(v1[r][c]==target) return true;
        else if(v1[r][c]<target) r++;
        else c--;
    }
    return false;
}
int main(){
    int r,c,x,t;
    cout<<"Enter rows columns : ";
    cin>>r>>c;
    vector<vector<int>>v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter value : ";
            cin>>v[i][j];
        }
    }
    cout<<"Enyer ur target : ";
    cin>>t;
    if(search_ele(v,t)) cout<<"YES!!!";
    else cout<<"NO!!!";
}