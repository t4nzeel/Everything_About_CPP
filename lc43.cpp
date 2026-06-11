#include<iostream>
#include<vector>
using namespace std;
int missingele(vector<int>&v1,int n,int k1){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        int missing=v1[mid]-(mid+1);
        if(missing<k1) low=mid+1;
        else high=mid-1;
    }
    return k1+1+high;
}
int main(){
    int s,x,k,n1;
    cout<<"Enter ur size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter ur kth missing element : ";
    cin>>k;
    n1=v.size();
    cout<<missingele(v,n1,k);
}