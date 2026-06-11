#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int s,x;
    cout<<"Enter size : ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    long long k;
    cout<<"Enter sum : ";
    cin>>k;
    int l=0,r=0,maxlen=0,n;
    long long sum=v[0];
    n=v.size();
    while(r<n){
        while(l<=r && sum>k){
            sum-=v[l];
            l++;
        }
        if(sum==k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
        if(r<n)  sum+=v[r];
    }
    cout<<maxlen;
}