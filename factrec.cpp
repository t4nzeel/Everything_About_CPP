#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n<2)
    {
        return 1;
    }
    else
    {
        return(n*factorial(n-1));
    }
}
int main()
{
    int x;
    cout<<"Enter your no. : ";
    cin>>x;
    int y=factorial(x);
    cout<<"Factorial of your given no. "<<x<<" is "<<y;
}