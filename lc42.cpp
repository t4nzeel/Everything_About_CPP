#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
int find_days(vector<int>&v,int cap){
    int days=1,load=0;
    for(int i=0;i<v.size();i++){
        if((load+v[i])>cap){
            days++;
            load=v[i];
        }
        else load+=v[i];
    }
    return days;
}
int least_weight_capacity(vector<int>&v1,int d){
    int low=*max_element(v1.begin(),v1.end());
    int high=accumulate(v1.begin(),v1.end(),0);
    while(low<=high){
        int mid=low+((high-low)/2);
        int NumOfDays=find_days(v1,mid);
        if(NumOfDays<=d) high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main(){
    int s,x,d1;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter no. of days : ";
    cin>>d1;
    cout<<least_weight_capacity(v,d1);
}