#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i=0,j=0;
    while(i<g.size() && j<s.size()){
        if(s[j]>=g[i])i++;
        j++;
    }
    return i;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g(n),s(m);
    for(int &x:g)cin>>x;
    for(int &x:s)cin>>x;
    cout<<findContentChildren(g,s)<<endl;
}