#include<iostream>
using namespace std;
int main(){
    int x,y; 
    cout<<"Enter ur no.s : ";
    cin>>x>>y;
    /*for(int i=min(x,y);i>=1;i--){
        if(x%i==0 && y%i==0){
            cout<<"Your GCD is "<<i<<endl;
            break;
        }
    }*/

    //Euclidean theorem of finding gcd    Much faster with time complexity O(logphi(min(x,y))). 
    while(x>0 && y>0){
        if(x>y)   x=x%y;
        else      y=y%x;
    }   
    if(x==0)  cout<<"GCD is "<<y<<endl;
    else      cout<<"GCD is "<<x<<endl;
}