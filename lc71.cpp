#include<iostream>
#include<climits>
using namespace std;
double myPow(double x,int n){
    if(n==0) return 1;
    if(n<0){
        x=1/x;
        if(n==INT_MIN){
            return x*myPow(x,-(n+1));
        }
        n=(-1)*n;
    }
    double half=myPow(x,n/2);
    if(n%2==0) return half*half;
    else return x*half*half;
}
int main(){
    double X;
    int N;
    cout<<"Enter ur no. and power respectively : ";
    cin>>X>>N;
    cout<<myPow(X,N);
}