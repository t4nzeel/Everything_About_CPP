#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
unordered_set<string>st;
vector<int>dp;
bool solve(int idx,string& s){
    if(idx==s.size()) return true;
    if(dp[idx]!=-1) return dp[idx];
    string s1="";
    for(int i=idx;i<s.size();i++){
        s1+=s[i];
        if(st.count(s1)){
            if(solve(i+1,s)) return dp[idx]=true;
        }
    }
    return dp[idx]=false;
}
bool wordBreak(string s, vector<string>&wordDict){
    st=unordered_set<string>(wordDict.begin(),wordDict.end());
    dp.assign(s.size(),-1);
    return solve(0,s);
}
int main(){
    string s;
    cin>>s;
    vector<string>v={"cats","dog","sand","and","cat"};
    if(wordBreak(s,v)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}