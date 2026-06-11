#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int s,x,maxi,sum=0;
    cout<<"Enter size : ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    maxi=INT_MIN;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        maxi=max(sum,maxi);
        if(sum<0)  sum=0;
    }
    cout<<maxi;
}