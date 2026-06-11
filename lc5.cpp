#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    int k,n,x;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter budget : ";
    cin>>k;
    for (int i = 0; i <n ; i++){
        cin>>x;
        v.push_back(x);
    }
    int res=1,s=0,e=0;
    long sum =0;
    sort(v.begin(),v.end());
    while(e<v.size()){
        sum+=v[e++];
        if((k+sum)<(long)v[e-1]*(e-s)){
            sum-=v[s++];
        }
        res=max(res,e-s);
    }
    cout<<"Maximum frequency is "<<res<<endl;
}