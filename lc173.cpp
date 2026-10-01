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
};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n=accounts.size();
    DisjointSet ds(n);
    unordered_map<string,int>m;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string mail=accounts[i][j];
            if(m.find(mail)==m.end())m[mail]=i;
            else ds.unionBySize(i,m[mail]);
        }
    }
    vector<vector<string>>mergedMail(n);
    for(auto it:m){
        string mail=it.first;
        int node=ds.findParent(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i=0;i<n;i++){
        if(mergedMail[i].size()==0)continue;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        vector<string>temp;
        temp.push_back(accounts[i][0]);
        for(auto it:mergedMail[i])temp.push_back(it);
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };
    vector<vector<string>> ans = accountsMerge(accounts);
    for (auto account : ans) {
        for (auto s : account) {
            cout << s << " ";
        }
        cout << endl;
    }
}