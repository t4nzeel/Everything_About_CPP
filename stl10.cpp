#include<iostream>
#include<cmath>
using namespace std;
int count(int n){
    int cnt=(int)(log10(n)+1);
    return cnt;
}
int main(){
    int x=123;
    int y=312;
    cout<<"no. of digits is "<<count(x);
}