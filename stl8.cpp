#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n,x,y;
    stack<int> s1,s2;
    cout<<"Enter the size of stack :";
    cin>>n;
    for (int i = 0; i < n; i++){
        cout<<"Enter your values :";
        cin>>x;
        s1.push(x);
    }
    cout<<"Top element : "<<s1.top()<<endl;
    s1.emplace(78);
    cout<<"New top element : "<<s1.top()<<endl;
    s1.pop();
    s1.pop();
    cout<<"New top element : "<<s1.top()<<endl;
    cout<<"Size of Array : "<<s1.size()<<endl;
    if (s1.empty()){
        cout<<"List is empty."<<endl;
    }
    else{
        cout<<"List is not empty."<<endl;
    }
    if (s2.empty()){
        cout<<"List is empty."<<endl;
    }
    else{
        cout<<"List is not empty."<<endl;
    }
    for (int i = 0; i < 4; i++){
        cout<<"Enter your values :";
        cin>>y;
        s2.push(y);
    }
    cout<<"\n";
    s1.swap(s2);
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    
}
