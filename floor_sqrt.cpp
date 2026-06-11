#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter ur no. : ";
    cin>>n;
    int low=1,high=n;
    while(low<=high){
        long long mid=low+((high-low)/2);
        long long val=mid*mid;
        if(val<=n) low=mid+1;
        else high=mid-1;
    }
    cout<<high;  //Shows only floor value.
}