#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int idx,string s, int t,int last,string &num,int target,vector<string>&ans){
    if(idx==num.size()){
        if(t==target) ans.push_back(s);
        return;
    }
    for(int i=idx;i<num.size();i++){
        if(i!=idx && num[idx]=='0') break;
        string curStr=num.substr(idx,i-idx+1);
        int cur=stoi(curStr);
        if(idx==0){
            solve(i+1,curStr,cur,cur,num,target,ans);
        }
        else{
            solve(i+1,s+'+'+curStr,t+cur,cur,num,target,ans);
            solve(i+1,s+'-'+curStr,t-cur,-cur,num,target,ans);
            solve(i+1,s+'*'+curStr,t-last+last*cur,last*cur,num,target,ans);
        }
    }
}
vector<string> addOperators(string num, int target){
    vector<string>ans;
    solve(0,"",0,0,num,target,ans);
    return ans;
}
int main(){
    string s;
    int tar;
    cin>>s>>tar;
    vector<string>v=addOperators(s,tar);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}