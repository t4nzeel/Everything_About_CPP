#include<bits/stdc++.h>
using namespace std;
using l=long long;
int characterReplacement(string s,int k){
    int l=0,r=0,mx=0,len=0;
    vector<int>v(26,0);
    while(r<s.size()){
        v[s[r]-'A']++;
        len=max(len,v[s[r]-'A']);
        if((r-l+1)-len>k){
            v[s[l]-'A']--;
            l++;
        }
        if((r-l+1)-len<=k)mx=max(mx,r-l+1);
        r++;
    }
    return mx;
}
int main(){
    int k;
    string s;
    cin>>s>>k;
    cout<<characterReplacement(s,k)<<endl;
}