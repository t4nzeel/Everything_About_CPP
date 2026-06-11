#include<iostream>
#include<stack>
using namespace std;
/*stack<int>sort_stack(stack<int>&s){
    stack<int>s1;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        while(!s1.empty() && s1.top()>t){
           s.push(s1.top());
           s1.pop();
        }
        s1.push(t);
    }
    return s1;
}*/
void insert_Desc(stack<int>&s,int x){
    if(s.empty() || x>=s.top()){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insert_Desc(s,x);
    s.push(temp);
}
void sort_stack_desc(stack<int>&s){
    if(s.empty()) return;
    int x=s.top();
    s.pop();
    sort_stack_desc(s);
    insert_Desc(s,x);
}
int main(){
    stack<int>S,S1;
    int x;
    for(int i=0;i<4;i++){
        cin>>x;
        S.push(x);
    }
    sort_stack_desc(S);
    while(!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}