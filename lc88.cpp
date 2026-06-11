#include<iostream>
#include<vector>
using namespace std;
int countPrimes(int n){
    if(n<=2) return 0;
    vector<int>v(n,1);
    v[0]=v[1]=0;
    for(int i=2;i*i<n;i++){
        if(v[i]==1){
            for(int j=i*i;j<n;j+=i) v[j]=0;
        }
    }
    int  cnt=0;
    for(int i=2;i<n;i++){
        if(v[i]==1) cnt++;
    }
    return cnt;
}
int main(){
    int N;
    cin>>N;
    cout<<countPrimes(N)<<endl;
}