#include<iostream>
#include<queue>
using namespace std;
int main(){
    int x;
    priority_queue<int,vector<int>,greater<int>>q;
    for (int i = 0; i < 5; i++)
    {
        cin>>x;
        q.push(x);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    } 
}