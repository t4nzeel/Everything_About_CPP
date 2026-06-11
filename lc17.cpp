#include<iostream>
#include<vector>
#include<algorithm>
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
    next_permutation(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}