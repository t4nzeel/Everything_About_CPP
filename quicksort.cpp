#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&v,int low,int high){
    int pivot=v[low];
    int i=low;
    int j=high;
    while(i<j){
        while(v[i]<=pivot &&i<=high-1) i++;
        while(v[j]>pivot && j>=low+1)  j--;
        if(i<j)  swap(v[i],v[j]);
    }
    swap(v[low],v[j]);
    return j;
}
void qs(vector<int>&v,int low,int high){
    if(low<high){
        int pIndex=partition(v,low,high);
        qs(v,low,pIndex-1);
        qs(v,pIndex+1,high);
    }
}
vector<int> quickSort(vector<int>v){
    qs(v,0,v.size()-1);
    return v;
}
int main(){
    vector<int>v1,v2;
    int m,x,l=0,h;
    cout<<"Enter the size of array : ";
    cin>>m;
    h=m-1;
    for(int i=0;i<m;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v1.push_back(x);
    }
    qs(v1,l,h);
    v2=quickSort(v1);
    for (int i = 0; i < v2.size(); i++){
        cout<<v2.at(i)<<" ";
    }
    
}