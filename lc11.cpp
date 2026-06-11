#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    vector<int>v1,v2;
    int s,x,k,i1=-1,i2=-1;
    cout<<"ENter size : ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v1.push_back(x);
    }
    cout<<"Enter ur target sum : ";
    cin>>k;
    v2=v1;
    sort(v1.begin(),v1.end());
    int l=0,r=s-1;
    while(l<r){
        int sum=v1[l]+v1[r];
        if(sum==k){
            auto it1=find(v2.begin(),v2.end(),v1[l]);
            if(it1!=v2.end())    i1=distance(v2.begin(),it1);
            v2[i1]=INT_MIN;
            auto it2=find(v2.begin(),v2.end(),v1[r]);
            if(it2!=v2.end())    i2=distance(v2.begin(),it2);
            break;
        }
        else if(sum<k) l++;
        else r--;
    }
    cout<<i1<<i2;
}