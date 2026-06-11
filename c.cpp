#include<bits/stdc++.h>
using namespace std;
#define ll  long long
 const ll mod=998244353;
  ll mpow(ll x,ll y,ll mod){
    ll res=1;
    x%=mod;
    while(y>0){
        if(y& 1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
  }

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        ll n,x;
        cin>>n>>x;
        vector<int>v(n+1);
        
        for(int i=1;i<n+1;i++){
            cin>>v[i];
        
        }
        ll ans1=0;
        ll ans2=0;

        for(ll i=1;i<=n;i++){
            if(i%2==0){
                if(v[i]!=0){
                    ll val=mpow(x,i,mod);
                    ans1+=val;
                    ans1=ans1%mod;
                }
            }
            else{
                if(v[i]!=1){
                    ans1+=mpow(x,i,mod);
                    ans1=ans1%mod;
                }
            }
            if(i%2==1){
                if(v[i]!=0){
                    ans2+=mpow(x,i,mod);
                    ans2=ans2%mod;
                }

            }
            else{
                if(v[i]!=1){
                    ans2+=mpow(x,i,mod);
                    ans2=ans2%mod;
                }
            }
        }
        cout<<min(ans1,ans2)<<endl;

    }
}