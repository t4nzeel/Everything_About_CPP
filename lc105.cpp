#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>&v){
    stack<int>s;
    for(int x:v){
        bool ok=true;
        while(!s.empty() && s.top()>0 && x<0){
            if(abs(s.top())<abs(x))s.pop();
            else if(abs(s.top())==abs(x)){
                s.pop();
                ok=false;
                break;
            }
            else{
                ok=false;
                break;
            }
        }
        if(ok)s.push(x);
    }
    vector<int>ans(s.size());
    for(int i=s.size()-1;i>=0;i--){
        ans[i]=s.top();
        s.pop();
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n),ans;
    for(int &x:v)cin>>x;
    ans=asteroidCollision(v);
    for(int &y:ans)cout<<y<<" ";
    cout<<endl;
}