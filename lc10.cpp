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
    int x1=0;
    for(int i=0;i<v.size();i++){
        x1=x1^v[i];
    }
    cout<<x1;
}