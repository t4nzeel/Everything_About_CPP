#include<iostream>
#include<string>
#include<vector>
using namespace std;
void solve(int idx,int n,string &curr,char last,vector<string>&ans){
    if(idx==n){
        ans.push_back(curr);
        return;
    }
    curr.push_back('0');
    solve(idx+1,n,curr,'0',ans);
    curr.pop_back();
    if(last!='1'){
        curr.push_back('1');
        solve(idx+1,n,curr,'1',ans);
        curr.pop_back();
    }
}
vector<string> generate_Binary_String(int n){
    vector<string>ans;
    string curr="";
    solve(0,n,curr,'0',ans);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<string> result = generate_Binary_String(n);
    for (auto &s : result)
        cout << s << " ";
}