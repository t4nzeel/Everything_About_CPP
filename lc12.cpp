// Dutch National Flag Algorithm
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v1;
    int s,x;
    cout<<"ENter size : ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v1.push_back(x);
    }
    int low=0,mid=0,high=s-1;
    while(mid<=high){
        if(v1[mid]==0){
            swap(v1[low],v1[mid]);
            low++;
            mid++;
        }
        else if(v1[mid]==1){
            mid++;
        }
        else{
            swap(v1[mid],v1[high]);
            high--;
        }
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1.at(i)<<" ";
    }
}
    