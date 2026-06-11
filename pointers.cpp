#include<iostream>
using namespace std;
int main()
{
    int a=3;
    int* b=&a;
    cout<<"The adress is "<<b<<endl;
    cout<<"The adress is "<<&a<<endl;
    cout<<"The value at this addess is "<<*b<<endl;
    int** c=&b;
    cout<<"The address is "<<c<<"\n"<<&b<<endl;
    cout<<"The address of value is "<<*c<<endl;
    cout<<"The value at address id "<<**c<<endl;
}