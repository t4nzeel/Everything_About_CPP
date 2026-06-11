#include<iostream>
#include<cmath>
using namespace std;
const long long MOD=1e9+7;
long long power(long long base, long long exp){
    if(exp==0) return 1;
    long long half=power(base,exp/2);
    long long result = (half * half) % MOD;
    if(exp%2==1) return ((base*result)%MOD);
    return result;
}
int countGoodNumbers(long long n){
    long long even_indices=(n+1)/2;
    long long odd_indices=n/2;
    long long even_power=power(5,even_indices);
    long long odd_power=power(4,odd_indices);
    return ((even_power*odd_power)%MOD);
}
int main(){
    long long N;
    cout<<"Enter ur length : ";
    cin>>N;
    cout<<countGoodNumbers(N);
}