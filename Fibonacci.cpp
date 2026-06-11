#include<iostream>
using namespace std;
int fibo(int n)
{
    int a=0,b=1,r;
    if(n<=0)
    {
        return 0;
    }
    if(n<2 && n>0)
    {
        return 1;
    }
    for(int i=1;i<n;i++)
    {
        r=a+b;
        a=b;
        b=r;
    }
    return r;
}
int main()
{
    int x;
    cout<<"Enter the nth term of whom you have to find value in fibonacci series : ";
    cin>>x;
    int y=fibo(x);
    cout<<"Value at "<<x<<"  position in fibonacci series is "<<y;
}