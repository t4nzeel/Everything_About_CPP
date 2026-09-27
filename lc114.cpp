#include<bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s){
    /*int n=s.size();
    int l=0,cnt=0;
    vector<int>v(3,0);
    for(int r=0;r<n;r++){
        v[s[r]-'a']++;
        while(v[0] && v[1] && v[2]){
            cnt+=n-r;
            v[s[l]-'a']--;
            l++;
        }
    }
    return cnt;*/
    vector<int>v(3,-1);
    int cnt=0;
    for(int i=0;i<s.size();i++){
        v[s[i]-'a']=i;
        if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1)   //Not necessary
            cnt+=1+min({v[0],v[1],v[2]});
    }
    return cnt;
}
int main(){
    string s;
    cin>>s;
    cout<<numberOfSubstrings(s)<<endl;
}