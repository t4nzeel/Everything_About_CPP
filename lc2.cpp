#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int reverse (int x){
    int rev=0;
    if(x>0){
        while(x!=0){
            int d=x%10;
            x=x/10;
            if(rev>INT_MAX/10 ||(rev==INT_MAX/10 && d>7)) return 0;
            rev=rev*10+d;
        }
        return rev;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    cout<<"Enter ur no. : ";
    cin>>n;
    int y=reverse(n);
    if(n==y){
        cout<<"no. is palindrome."<<"\n";
    }
    else{
        cout<<"No. is not palindrome."<<"\n";
    }
}