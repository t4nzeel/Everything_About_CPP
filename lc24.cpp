#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int s,x;
    cout<<"enter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(i>0 && v[i]==v[i-1]) continue;
        int j=i+1;
        int k=v.size()-1;
        while(j<k){
            int sum=v[i]+v[j]+v[k];
            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                vector<int>v1={v[i],v[j],v[k]};
                ans.push_back(v1);
                j++;
                k--;
                while(j<k && v[j]==v[j-1]) j++; //So that same no.s are not taken in count again.
                while(j<k && v[k]==v[k+1]) k--;// "                                            "
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}