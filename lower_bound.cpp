#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int s,x,t,mid;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter ur no. : ";
    cin>>t;
    int n=v.size();
    sort(v.begin(),v.end());
    int ans=n;
    int low=0,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(v[mid]>=t){
            ans=mid;          //Maybe an answer.
            high=mid-1;       //Look for more small index on the  left.
        }
        else low=mid+1;       //Look for right.
    }
    cout<<ans;
    //auto index=lower_bound(v.begin(),v.end(),t)-v.begin();  ==> Same
}