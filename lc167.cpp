#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
    vector<int>par,size,rank;
    public:
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
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
    void unionByRank(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(rank[pu]<rank[pv])par[pu]=pv;
        else if(rank[pu]>rank[pv])par[pv]=pu;
        else{
            par[pv]=pu;
            rank[pu]++;
        }
    }
};
int main(){
    DisjointSet ds(5);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    cout << ds.findParent(3) << endl;
}