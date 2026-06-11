//Aggressive cows means max min distance between cows.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool can_we_Place(vector<int>&v1,int dist,int cows){
    int cntCows=1,last=v1[0];
    for(int i=0;i<v1.size();i++){
        if(v1[i]-last>=dist){
            cntCows++;
            last=v1[i];
        }
        if(cntCows>=cows) return true;
    }
    return false;
}
int aggressive_cows(vector<int>&v2,int k){
    sort(v2.begin(),v2.end());
    int n=v2.size();
    int low=1,high=v2[n-1]-v2[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(can_we_Place(v2,mid,k)==true) low=mid+1;
        else high=mid-1;
    }
    return high;
}
int main(){
    int s,x,no;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter no. of cows : ";
    cin>>no;
    cout<<aggressive_cows(v,no);
}