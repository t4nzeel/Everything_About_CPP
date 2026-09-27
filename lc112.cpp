#include<bits/stdc++.h>
using namespace std;
int numSubarraysWithSum(vector<int>&v, int goal){
    if(goal<0)return 0;
    int r=0,l=0,sum=0,cnt=0;
    while(r<v.size()){
        sum+=v[r];
        while(sum>goal){
            sum-=v[l];
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;
}
int main(){
    int n,g;
    cin>>n>>g;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<numSubarraysWithSum(v,g)-numSubarraysWithSum(v,g-1)<<endl;
}