#include<bits/stdc++.h>
using namespace std;
int subarraysWithKDistinct(vector<int>&v, int k){
    int n=v.size();
    int l=0,r=0,cnt=0;
    unordered_map<int,int>m;
    while(r<n){
        m[v[r]]++;
        while(m.size()>k){
            m[v[l]]--;
            if(m[v[l]]==0)m.erase(v[l]);
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<subarraysWithKDistinct(v,k)-subarraysWithKDistinct(v,k-1)<<endl;
}