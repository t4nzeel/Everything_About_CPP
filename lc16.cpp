#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v,v1;
    int s,x;
    cout<<"ENter size : ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    int p=0,n=1;
    v1.resize(v.size());
    for(int i=0;i<v.size();i++){
        if(v[i]>0){
            v1[p]=v[i];
            p+=2;
        }
        else{
            v1[n]=v[i];
            n+=2;
        }
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
}