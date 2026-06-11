#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        int n;
        cin>>n;
        vector<int> deg(n+1,0);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(deg[i]==1){
                cnt++;
            }
        }
        cout<<max(0,cnt)<<endl;


    }
}