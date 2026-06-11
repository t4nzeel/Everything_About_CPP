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
    int mini=v[0];
    int mp=0;
    for(int i=1;i<v.size();i++){
        int c=v[i]-mini;
        mp=max(mp,c);
        mini=min(mini,v[i]);
    }
    cout<<mp;
}