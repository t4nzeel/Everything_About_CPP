#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
const int N=1e6+1;
long long dp[N][2];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        dp[1][0]=1;
        dp[1][1]=1;
        for(int i=2;i<N;i++){
            dp[i][0]=(2LL*dp[i-1][0]+dp[i-1][1])%MOD;
            dp[i][1]=(4LL*dp[i-1][1]+dp[i-1][0])%MOD;
        }
        long long ans=(dp[n][0]+dp[n][1])%MOD;
        cout<<ans<<endl;
    }
}