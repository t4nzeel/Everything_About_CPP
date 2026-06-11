//For better TC see lc57_2.cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
double median_finder(vector<int>v11,vector<int>v22){
    vector<int>result(v11.size()+v22.size());
    double ans;
    merge(v11.begin(),v11.end(),v22.begin(),v22.end(),result.begin());
    int n=result.size();
    int low=0,high=n-1;
        int mid=(high+low)/2;
        if(n%2==0) {ans=(double)(result[mid]+result[mid+1])/2;}
        else {ans=result[mid];}
    return ans;
}
int main(){
    int s1,s2,x;
    cout<<"Enter sizes : ";
    cin>>s1>>s2;
    vector<int>v1,v2;
    for(int i=0;i<s1;i++){
        cout<<"Enter value : ";
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<s2;i++){
        cout<<"Enter value : ";
        cin>>x;
        v2.push_back(x);
    }
    cout<<median_finder(v1,v2);
}