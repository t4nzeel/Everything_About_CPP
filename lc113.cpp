#include<bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int>&v, int k){
    if(k<0)return 0;
    int l=0,r=0,cnt=0,sum=0;
    while(r<v.size()){
        if(v[r]%2!=0)sum++;
        while(sum>k){
            if(v[l]%2!=0)sum--;
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
    cout<<numberOfSubarrays(v,k)-numberOfSubarrays(v,k-1)<<endl;
}