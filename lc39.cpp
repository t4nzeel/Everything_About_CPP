#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int calculate_Total_hours(vector<int>v1,int hourly){
    int totalH=0;
    int n=v1.size();
    for(int i=0;i<n;i++){
        totalH+=ceil((double)v1[i]/(double)hourly);
    }
    return totalH;
}
int minimum_Rate_to_eat_banana(vector<int>v2,int hr){
    int low=1,high=*max_element(v2.begin(),v2.end());
    while(low<=high){
        int mid=low+((high-low)/2);
        int TotalH=calculate_Total_hours(v2,mid);
        if(TotalH<=hr) high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main(){
    int s,x,h;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"For how many hours guard has gone : ";
    cin>>h;
    cout<<minimum_Rate_to_eat_banana(v,h);
}