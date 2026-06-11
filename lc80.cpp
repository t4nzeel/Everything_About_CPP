#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool is_palindrome(string s){
    string t=s;
    reverse(t.begin(),t.end());
    if(t==s) return true;
    else return false;
}
void helper(int idx,string s,string s1,vector<string>&curr,vector<vector<string>>&ans){
    if(idx==s.size()){
        if(s1.empty()){
            ans.push_back(curr);
        }
        return;
    }
    s1+=s[idx];
    if(is_palindrome(s1)){
        curr.push_back(s1);
        helper(idx+1,s,"",curr,ans);
        curr.pop_back();
    }
    helper(idx+1,s,s1,curr,ans);
}
vector<vector<string>> partition(string s){
    vector<vector<string>>ans;
    vector<string>curr;
    helper(0,s,"",curr,ans);
    return ans;
}
int main(){
    string s="aab";
    vector<vector<string>>v1=partition(s);
    for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v1[i].size(); j++) {
        cout << v1[i][j] << " ";
    }
    cout << endl;
    }
}