#include<iostream>
#include<vector>
using namespace std;
int number_of_gas_stations(long double dist,vector<int>&v1){
    int n=v1.size();
    int cnt=0;
    for(int i=1;i<n;i++){
        int number_in_between=((v1[i]-v1[i-1])/dist);
        if(((v1[i]-v1[i-1])/dist)==dist*number_in_between) number_in_between--;
        cnt+=number_in_between;
    }
    return cnt;
}
long double minimize_MAx_distance(vector<int>&v2,int k){
    int n=v2.size();
    long double low=0,high=0;
    for(int i=0;i<n-1;i++) high=max(high,(long double)(v2[i+1]-v2[i]));
    long double diff=1e-6;  //10^(-6)
    while(high-low>diff){
        long double mid=(low+high)/2;
        int cnt=number_of_gas_stations(mid,v2);
        if(cnt>k) low=mid;
        else high=mid;
    }
    return high;
}
int main(){
    int s,x,k1;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter no. of stations : ";
    cin>>k1;
    cout<<minimize_MAx_distance(v,k1);
}