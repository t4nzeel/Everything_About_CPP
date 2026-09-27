#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int>par,size;
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)par[i]=i;
    }
    int findParent(int node){
        if(par[node]==node)return node;
        return par[node]=findParent(par[node]);
    }
    void unionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
int makeConnected(int n, vector<vector<int>>& connections){
    DisjointSet ds(n);
    int cntExtras=0;
    for(auto it:connections){
        int u=it[0];
        int v=it[1];
        if(ds.findParent(u)==ds.findParent(v))cntExtras++;
        else ds.unionBySize(u,v);
    }
    int cntC=0;
    for(int i=0;i<n;i++){
        if(ds.par[i]==i)cntC++;
    }
    int ans=cntC-1;
    if(cntExtras>=ans)return ans;
    return -1;
}
int main(){}