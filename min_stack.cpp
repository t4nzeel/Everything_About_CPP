#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<long long>s;
    long long mn;
    MinStack() {}
    void push(int value) {
        if(s.empty()){
            s.push(value);
            mn=value;
        }
        else if(value>=mn)s.push(value);
        else{
            s.push(2LL*value-mn);
            mn=value;
        }
    }
    void pop() {
        if(s.empty())return;
        if(s.top()<mn)mn=2LL*mn-s.top();
        s.pop();
    }
    int top() {
        if(s.empty())return -1;
        if(s.top()<mn)return mn;
        return s.top();
    }
    int getMin() {
        return s.empty() ?-1:mn;
    }
};
int main(){}