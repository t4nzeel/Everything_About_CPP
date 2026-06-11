#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,m;
bool dfs(int i,int j,int idx,vector<vector<char>>&board,string word){
    if(idx==word.size()) return true;
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[idx]) return false;
    char temp=board[i][j];
    board[i][j]='#';
    bool found=dfs(i+1,j,idx+1,board,word) || dfs(i-1,j,idx+1,board,word) || dfs(i,j+1,idx+1,board,word) || dfs(i,j-1,idx+1,board,word);
    board[i][j]=temp;
    return found;
}
bool exist(vector<vector<char>>& board, string word){
    n=board.size();
    m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j,0,board,word)) return true;
        }
    }
    return false;
}
int main(){
    vector<vector<char>>board(3,vector<char>(4));
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>board[i][j];
        }
    }
    string s;
    cin>>s;
    if(exist(board,s)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}