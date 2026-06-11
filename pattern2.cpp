#include<iostream>
using namespace std;
int main()
{
    int  n,z;
    cout<<"Enter the no.of rows you want :- "<<endl;
    cin>>n;
    z=n;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<(z-1);k++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        z--;
        cout<<endl;
    }
}