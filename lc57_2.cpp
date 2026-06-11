#include<iostream>
#include<vector>
#include<climits>
using namespace std;
double median_finder(vector<int>v11,vector<int>v22){
    int n11=v11.size();
    int n22=v22.size();
    if(n11>n22) return median_finder(v22,v11);
    int low=0,high=n11,left=(n11+n22+1)/2;
    int n=n11+n22;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n11) r1=v11[mid1];
        if(mid2<n22) r2=v22[mid2];
        if(mid1-1>=0) l1=v11[mid1-1];
        if(mid2-1>=0) l2=v22[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2))/2.0);
        }
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }
    return 0.0;
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