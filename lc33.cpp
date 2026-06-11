#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int s,x,t,mid;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter ur target : ";
    cin>>t;
    int n=v.size();
    int lb=lower_bound(v.begin(),v.end(),t)-v.begin();
    int up=upper_bound(v.begin(),v.end(),t)-v.begin()-1;
    if(lb==n || v[lb]!=t){lb=-1; up=-1;}
    cout<<lb<<"  "<<up;   
}