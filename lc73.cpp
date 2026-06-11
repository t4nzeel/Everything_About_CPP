#include<iostream>
#include<vector>
#include<string>
using namespace std;
void Permutation(int idx,int n,string& curr,int R,int L,vector<string>&ans){
    if(idx==2*n){
        ans.push_back(curr);
        return;
    }
    if(R<n){
        curr.push_back('(');
        Permutation(idx+1,n,curr,R+1,L,ans);
        curr.pop_back();
    }
    if(L<R){
        curr.push_back(')');
        Permutation(idx+1,n,curr,R,L+1,ans);
        curr.pop_back();
    }
}
vector<string> generateParanthesis(int n){
    vector<string>ans;
    string curr="";
    Permutation(0,n,curr,0,0,ans);
    return ans;
}
int main(){
    int n;
    cout<<"Enter : ";
    cin>>n;
    vector<string>v1=generateParanthesis(n);
    for(int i=0;i<v1.size();i++){
        cout<<v1.at(i)<<"  ";
    }
}