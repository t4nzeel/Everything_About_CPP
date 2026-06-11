#include <iostream>
using namespace std;
int a = 0, b = 1;
void fib(int n)
{
    cout<<b<<"  ";
    for (int i = 0; i < n-1 ; i++)
    {
        int r = a + b;
        a=b;
        b=r;
        cout<<r<<"  ";
    }
}
int main()
{
    int x;
    cout<<"Enter the nth term upto which you want to print the series : ";
    cin>>x;
    fib(x);
}