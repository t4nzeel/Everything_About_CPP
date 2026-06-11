#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int s,x;
    cout<<"Enter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    int d;
    cout<<"Enter the space from which array has to be rotated : ";
    cin>>d;
    for(int i=0;i<d;i++){
        int temp=v[0];
        for(int j=0;j<s;j++){
            v[j-1]=v[j];
        }
        v[s-1]=temp;
    }
    for(int i=0;i<s;i++){
        cout<<v.at(i)<<" ";
    }
}