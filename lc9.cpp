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
    int cnt=0,maxi=0;
    for (int i = 0; i < v.size(); i++){
        if(v[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else{
            cnt=0;
        }
    }
    cout<<maxi;
}