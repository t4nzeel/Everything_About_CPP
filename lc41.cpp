#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int divisor_sum(vector<int>v1,int m){
    int s=0;
    for(int i=0;i<v1.size();i++){
        s+=ceil((double)v1[i]/(double)m);
    }
    return s;
}
int main(){
    int s,x,t;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter ur threshold value : ";
    cin>>t;
    int low=1;
    int high=*max_element(v.begin(),v.end());
    int ans=high;
    while(low<=high){
        int mid=low+((high-low)/2);
        int sum=divisor_sum(v,mid);
        if(sum<=t) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<ans;
}
