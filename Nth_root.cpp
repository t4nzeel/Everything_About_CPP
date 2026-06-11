#include<iostream>
#include<vector>
using namespace std;
int func(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}
int main(){
    int m,n,ans=-1;
    cout<<"Enter ur no. and the nth root u want to find : ";
    cin>>m>>n;
    int low=1,high=m;
    while(low<=high){
        int mid=((high-low)/2)+low;
        int midN=func(mid,n,m);
        if(midN==1) {cout<<mid; return 0;}
        else if(midN==0) {low=mid+1; ans=mid;}
        else high=mid-1;
    }
    cout<<ans;
}