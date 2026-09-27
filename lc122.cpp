#include<bits/stdc++.h>
using namespace std;
int jump(vector<int>&v){
    int j=0,f=0,c=0;
    for(int i=0;i<v.size()-1;i++){
        f=max(f,i+v[i]);
        if(i==c){
            j++;
            c=f;
        }
    }
    return j;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    cout<<jump(v)<<endl;
}