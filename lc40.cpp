#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool possible(vector<int>& v0,int days,int m,int k){
    int cnt=0,NumB=0;
    for(int i=0;i<v0.size();i++){
        if(v0[i]<=days) cnt++;
        else {
            NumB+=(cnt/k);
            cnt=0;
        }
    }
    NumB+=(cnt/k);
    return NumB>=m;
}
int rose_garden(vector<int>v1,int r,int b){
    long long val=(long long)r*b;
    if(val>v1.size()) return -1;
    int low=*min_element(v1.begin(),v1.end());
    int high=*max_element(v1.begin(),v1.end());
    while(low<=high){
        int mid=low+((high-low)/2);
        if(possible(v1,mid,r,b)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int s,x,bouquets,adjacent;
    cout<<"Enter size :";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter no. of bouquets and adjacent flowers you need to use : ";
    cin>>bouquets>>adjacent;
    cout<<rose_garden(v,bouquets,adjacent);
}