#include<iostream>
#include<stack>
using namespace std;
void insert_Stack(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insert_Stack(s,x);
    s.push(temp);
}
void reverse_Stack(stack<int>&s){
    if(s.empty()) return;
    int x=s.top();
    s.pop();
    reverse_Stack(s);
    insert_Stack(s,x);
}
int main(){
    stack<int>S;
    int x;
    for(int i=0;i<4;i++){
        cin>>x;
        S.push(x);
    }
    reverse_Stack(S);
    while(!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}