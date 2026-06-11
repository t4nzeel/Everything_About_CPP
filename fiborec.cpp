#include<iostream>
using namespace std;
int fibonacci(int n)
{
    if(n<2)
    {
        return 1;
    }
    else
    {
        return(fibonacci(n-2)+fibonacci(n-1));
    }
}
int main()
{
    int x;
    cout<<"Enter your nth postion to which you have to find Fibonaaci no. : ";
    cin>>x;
    int y=fibonacci(x-1);
    cout<<"The no. at the "<<x<<" position in the fibonacci series is "<<y;
}