#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t){
    int n=s.size(),m=t.size();
    int l=0,r=0,mn=INT_MAX,cnt=0,si=-1;
    vector<int>v(256,0);
    for(int i=0;i<m;i++)v[t[i]]++;
    while(r<n){
        if(v[s[r]]>0)cnt++;
        v[s[r]]--;
        while(cnt==m){
            if(r-l+1<mn){
                mn=r-l+1;
                si=l;
            }
            v[s[l]]++;
            if(v[s[l]]>0)cnt--;
            l++;
        }
        r++;
    }
    return si==-1 ? "" :s.substr(si,mn);
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<minWindow(s,t)<<endl;
}