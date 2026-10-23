#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>pr(n),pa(n);
    for(int i=0;i<n;i++)cin>>pr[i];
    for(int i=0;i<n;i++)cin>>pa[i];
    vector<int>prev(x+1,0);
    for(int i=1;i<=n;i++){
        vector<int>curr(x+1);
        for(int j=0;j<=x;j++){
            int w=pr[i-1];
            int v=pa[i-1];
            int pick=(j>=w ? prev[j-w]+v:0);
            int skip=prev[j];
            curr[j]=max(skip,pick);
        }
        prev=curr;
    }
    cout<<prev[x]<<endl;
}