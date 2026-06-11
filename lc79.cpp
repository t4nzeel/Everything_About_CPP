#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
void helper(int idx,string& digits,string& curr,vector<string>& ans,map<char,string>& m){
    if(idx==digits.length()){
        ans.push_back(curr);
        return;
    }
    char c=digits[idx];
    string s=m[c];
    for(int i=0;i<s.size();i++){
        curr+=s[i];
        helper(idx+1,digits,curr,ans,m);
        curr.pop_back();
    }
}
vector<string>letterCombinations(string digits){
        if (digits.empty()) return {};
        map<char,string>m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string>ans;
        string curr;
        helper(0,digits,curr,ans,m);
        return ans;
    }
int main(){
    string n;
    cin>>n;
    vector<string>v=letterCombinations(n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}