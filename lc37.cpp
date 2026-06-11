#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& v1){
    int n=v1.size();
    if(n==1) return v1[0];
    if(v1[0]!=v1[1]) return v1[0];
    if(v1[n-1]!=v1[n-2]) return v1[n-1];
    int low=1,high=n-2;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(v1[mid]!=v1[mid-1] && v1[mid]!=v1[mid+1]) return v1[mid];
        if((mid%2==1 && v1[mid-1]==v1[mid])||(mid%2==0 && v1[mid+1]==v1[mid])) low=mid+1;
        else high=mid-1;
    }
}
int main(){
    int s,x,len1,len2;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    int single=singleNonDuplicate(v);
    cout<<single;
    /*int low=0,high=n-1;
    int z=0;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(v[mid]==v[mid-1]){
            len1=mid+1;
            len2=n-len1;
        }
        else if(v[mid]==v[mid+1]){
            len2=mid+1;
            len1=n-len2;
        }
        else{ cout<<v[mid]; break;}
        if(len1%2==0){
            low=mid+1;
            n=high-low+1;
        }
        else if(len2%2==0){
            high=mid;
            n=high+1;
        }
    }*/   
}