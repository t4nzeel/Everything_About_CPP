#include<iostream>
using namespace std;
void swap(int a, int b)
{
    int c=a;
    a=b;
    b=c;
}
void swappointer(int* q,int* w)   //Pointer variables
{
    int t=*q;
    *q=*w;
    *w=t;
}
void swapbyref(int &e,int &r)   //Reference variables
{
    int u=e;
    e=r;
    r=u;
}
int main()
{
    int x,y;
    cout<<"Enter ur no.s in X and Y respectively :-\n";
    cin>>x>>y;
    //swap(x,y);    This will not work.
    //swappointer(&x,&y);     This will work by using pointer variables. 
    swapbyref(x,y);   //This will work by using reference variable.
    cout<<"Now your values in x and y respectively are "<<x<<" and "<<y<<endl;
}