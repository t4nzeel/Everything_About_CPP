#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int s,x;
    cout<<"Enter size : ";
    cin>>s;
    vector<vector<int>>v(s,vector<int>(2));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<"ENter value : ";
            cin>>x;
            v[i][j]=x;
        }
    }
    /*int t=0;
    vector<vector<int>>ans(s,vector<int>(2));// ????
    for(int i=0;i<v.size();i++){
        int j=i+1;
        if(j>=v.size()){
            ans[t][0]=v[i][0];
            ans[t][1]=v[i][1];
            break;
        }
        if(v[i][1]>=v[j][0]){
            ans[t][0]=v[i][0];
            ans[t][1]=v[j][1];
            i++;
            t++;
        }
        else{
            ans[t][0]=v[i][0];
            ans[t][1]=v[i][1];
            t++;
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }*/
   sort(v.begin(),v.end());
   vector<vector<int>>ans;
   for(int i=0;i<s;i++){
    if(ans.empty()  || v[i][0]>ans.back()[1]) ans.push_back(v[i]);
    else ans.back()[1]=max(ans.back()[1],v[i][1]);
   }
   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
}