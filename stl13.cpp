#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int x;
    vector<int> v;
    for(int i=0;i<5;i++){
        cout<<"Enter your value : ";
        cin>>x;
        v.push_back(x);
    }
    for(int j=0;j<5;j++){
        cout<<v.at(j)<<" ";
    }
    reverse(v.begin(),v.end());
    for(int j=0;j<5;j++){
        cout<<v.at(j)<<" ";
    }
}