#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isSafe(int row,int col,vector<string>&board,int n){
    int r=row;
    int c=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row=r;
    col=c;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    col=c;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<board.size();i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}
int main(){
    int N;
    cin>>N;
    vector<vector<string>>v=solveNQueens(N);
    for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
        cout << v[i][j] << " ";
    }
    cout << endl;
}
}