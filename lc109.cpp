#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s){
    /*int i=0,mx=0;
    int n=s.size();
    while(i<n){
        string s1="";
        for(int j=i;j<n;j++){
            if(s1.find(s[j])==string::npos)s1+=s[j];
            else break;
        }
        int N=s1.size();
        mx=max(mx,N);
        i++;
    }
    return mx;*/
    vector<int>v(256,-1);
    int ans=0,l=0;
    for(int r=0;r<s.size();r++){
        l=max(l,v[s[r]]+1);
        ans=max(ans,r-l+1);
        v[s[r]]=r;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
}