#include<bits/stdc++.h>
using namespace std;
int change(int amount, vector<int>& coins){
    int n=coins.size();
    vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1));
    vector<int>nextState(amount+1);
    nextState[0]=1;
    for(int i=n-1;i>=0;i--){
        vector<int>currentState(amount+1,0);
        currentState[0]=1;
        for(int sum=1;sum<=amount;sum++){
            long long skipping=nextState[sum];
            long long picking=0;
            if(coins[i]<=sum){
                picking=currentState[sum-coins[i]];
            }
            long long ways=skipping+picking;
            currentState[sum]=(int)ways;
        }
        nextState=currentState;
    }
    return nextState[amount];
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<change(5,v)<<endl;
}