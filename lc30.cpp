#include<iostream>
#include<vector>
using namespace std;
int main(){
    int s,x;
    cout<<"Enter ur size : ";
    cin>>s;
    vector<int>v;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    long long n=v.size();
    long long Sn=(n*(n+1))/2;
    long long S2n=(n*(n+1)*(2*n+1))/6;
    long long s1=0,s2=0;
    for(int i=0;i<n;i++){
        s1+=v[i];
        s2+=(long long)v[i]*(long long)v[i];
    }
    long long v1=s1-Sn; //x-y
    long long v2=s2-S2n;
    v2=v2/v1; //x+y
    long long X=(v1+v2)/2;
    long long Y=X-v1;
    cout<<X<<" "<<Y;  //X=repeating no. & Y=missing no.
}