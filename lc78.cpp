#include<iostream>
#include<vector>
using namespace std;
void helper(int k, int n, int start, vector<int>& curr,
                vector<vector<int>>& ans) {

        if (k == 0 && n == 0) {
            ans.push_back(curr);
            return;
        }

        if (k < 0 || n < 0)
            return;

        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            helper(k - 1, n - i, i + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(k, n, 1, curr, ans);
        return ans;
    }
/*void helper(int k,int n,int N,vector<int>&curr,vector<vector<int>>&ans){
    if(n==0 && k==0){
        ans.push_back(curr);
        return;
    }
    if(k==0 || N>n || N>9) return;
    curr.push_back(N);
    helper(k-1,n-N,N+1,curr,ans);
    curr.pop_back();
    helper(k,n,N+1,curr,ans);
}
vector<vector<int>> combinationSum3(int k, int n){
    vector<vector<int>>ans;
    vector<int>curr;
    helper(k,n,1,curr,ans);
    return ans;
}*/
int main(){
    int k=3,n=9;
    vector<vector<int>>v=combinationSum3(k,n);
    for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
        cout << v[i][j] << " ";
    }
    cout << endl;
}
}