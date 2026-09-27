#include<bits/stdc++.h>
using namespace std;
int candy(vector<int>&v){
    int i=1,s=1;
    while(i<v.size()){
        if(v[i-1]==v[i]){
            s+=1;
            i++;
            continue;
        }
        int p=1;
        while(i<v.size() && v[i-1]<v[i]){
            p++;
            s+=p;
            i++;
        }
        int d=1;
        while(i<v.size() && v[i-1]>v[i]){
            s+=d;
            i++;
            d++;
        }
        if(d>p){
            s+=(d-p);
        }
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int&x:v)cin>>x;
    cout<<candy(v)<<endl;
} 