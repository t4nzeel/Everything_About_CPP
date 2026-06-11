#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int count_Students(vector<int>&v1,int pages){
    int students=1;
    long long pagesStudent=0;
    for(int i=0;i<v1.size();i++){
        if(pagesStudent+v1[i]<=pages) pagesStudent+=v1[i];
        else{
            students+=1;
            pagesStudent=v1[i];
        }
    }
    return students;
}
int find_Pages(vector<int>&v2,int n,int m){
    if(m>n) return -1;
    int low=*max_element(v2.begin(),v2.end());
    int high=accumulate(v2.begin(),v2.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int students=count_Students(v2,mid);
        if(students>m){
            low=mid+1;
        }
        else high=mid-1;
    }
    return low;
}
int main(){
    int s,x;
    cout<<"Enter size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    int n1=v.size();
    int m1;
    cout<<"Enter no. of students : ";
    cin>>m1;
    cout<<find_Pages(v,n1,m1);
}