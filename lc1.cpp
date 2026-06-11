#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int  x,s=0;
    cout<<"Enter ur no.: ";
    cin>>x;
    if(pow(-2,31)<=x<=(pow(2,31)-1)){
        if(x>0){
            while(x>0){
                int r=x%10;
                s=s*10+r;
                x=x/10;
            }
        }
        else{
            x=abs(x);
            while(x>0){
                int r=x%10;
                s=s*10+r;
                x=x/10;
            }
            s=s*(-1);
        }
    }
    cout<<s;
}