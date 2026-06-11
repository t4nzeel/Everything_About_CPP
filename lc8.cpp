#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int x,s=0;
    for(int i=0;i<1;i++){
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int x1=0,x2=0;
    int n=v.size();
    for (int i = 0; i < n; i++){
        x2=x2^v[i];
        x1=x1^(i);
    }
    x1=x1^n;
    cout<<(x1^x2);
    /*int n=v.size();
    int s1=(n*(n+1))/2;
    for (int i = 0; i < v.size(); i++){
        s+=v[i];
    }
    int m=s1-s;
    cout<<m;*/
    return 0;
}