#include<bits/stdc++.h>
using namespace std;
#define ll  long long
 const ll mod=998244353;

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        ll n,x;
        cin>>n>>x;
        vector<int>a(n+1);
        for(int i=1;i<n+1;i++){
            cin>>a[i];
        }
        ll c=1;
        ll cost0=0,cost1=0;
        for(int i=1;i<=n;i++){
            int p0=(i%2 & 1)? 0:1;
            int p1=1-p0;
             c=(x*c)% mod;
            if(a[i]!=p0){
                cost0+=c;
                if(cost0>=mod) cost0-=mod;

            }
            if(a[i]!=p1){
                cost1+=c;
                if(cost1>=mod) cost1-=mod;
            }
        }
        cout<<min(cost0%mod,cost1%mod)<<endl;
    }
}