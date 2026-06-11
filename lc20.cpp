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
    vector<int>ans;
    int left=0,right=c-1;
    int top=0,bottom=r-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(m[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(m[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(m[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(m[i][left]);
            }
            left++;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
}