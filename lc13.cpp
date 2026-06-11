//Moore's Voting Algorithm
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int s,x;
    cout<<"ENter size : ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    int c=0,e;
    for(int i=0;i<v.size();i++){
        if(c==0){
            c=1;
            e=v[i];
        }
        else if(e==v[i]) c++;
        else c--;
    }
    cout<<e;
}