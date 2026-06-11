#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the length of array : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter ur values in array : ";
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
}