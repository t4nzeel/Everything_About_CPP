#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    int c=0;
    double s=0;
    cout<<"Enter a no. : ";
    cin>>n;
    int a=n;
    int x=n;
    while(a>0)
    {
        a=a/10;
        c=c+1;
    }
    while(x>0)
    {
        int r=x%10;
        s=s+(pow(r,c));     //Since pow was used, Double data type is more suitable as pow returns decimal value.
        x=x/10;
    }
    if(s==n)
    {
        cout<<"Your given no. is Armstrong."<<endl;
    }
    else
    {
        cout<<"Your given no. is not Armstrong."<<endl;
    }
}