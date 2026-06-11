#include<iostream>
using namespace std;
int main(){
    int n,a=0,b=1,c;
    cin>>n;
    if(0<=n<=30){
        if(n==0)  cout<<a;
        else if(n==1 || n==2)  cout<<b;
        else{
            for (int i =0; i<(n-2); i++)
            {
                c=a+b;
                a=b;
                b=c;
            }
            cout<<c;
            
        } 
    }
    
}