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
    int t;
    cout<<"Enter ur target : ";
    cin>>t;
    vector<vector<int>>ans;
    int n=v.size();
    sort(v.begin(),v.end());
    /*for(int i=0;i<v.size();i++){
        if(i>0 && v[i]==v[i-1]) continue;
        int j=i+1;
        int k=n-1;
        int l=n-2;
        while(j<l){
            int sum=v[i]+v[j]+v[k]+v[l];
            if(sum<t) j++;
            else if(sum>t) {k--; l--;} 
            else{
                vector<int>v1={v[i],v[j],v[l],v[k]};
                ans.push_back(v1);
                j++;
                l--;
                while(j<l && v[j]==v[j-1]) j++;
                while(j<l && v[l]==v[l+1]) l--;
            }
        }
    }*/
   for(int i=0;i<n;i++){
    if(i>0 && v[i]==v[i-1]) continue;
    for(int j=i+1;j<n;j++){
        if(j!=(i+1) && v[j]==v[j-1]) continue;
        int k=j+1;
        int l=n-1;
        while(k<l){
            long long sum=v[i];
            sum+=v[j];
            sum+=v[k];
            sum+=v[l];
            if(sum<t) k++;
            else if(sum>t) l--;
            else{
                vector<int>v1={v[i],v[j],v[k],v[l]};
                ans.push_back(v1);
                k++;
                l--;
                while(k<l && v[k]==v[k-1]) k++;
                while(k<l && v[l]==v[l+1]) l--;
            }

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