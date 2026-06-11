#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    vector<int>v;
    unordered_set<int>s;
    int x,n;
    cout<<"Enter size : ";
    cin>>n;
    for (int i = 0; i < n; i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    for(int j=0;j<v.size();j++){
        s.insert(v[j]);
    }
    for(auto it :s){
        cout<<it<<" ";
    }
}