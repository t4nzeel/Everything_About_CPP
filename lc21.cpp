#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int>v;
    int s,x,k;
    cout<<"Enter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter sum : ";
    cin>>k;
    map<int,int>m;
    int presum=0,cnt=0;
    m[0]=1;
    for(int i=0;i<v.size();i++){
        presum+=v[i];
        int rem=presum-k;
        cnt+=m[rem];
        m[presum]+=1;
    }
    cout<<cnt;
}