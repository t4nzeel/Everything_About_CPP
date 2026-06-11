#include<iostream>
#include<cmath>
using namespace std;
class point
{
    int x,y;
    public:
    point(int a,int b)
    {
        x=a;
        y=b;
    }
    void display()   
    {
        cout<<"Your point is ( "<<x<<" , "<<y<<" )"<<endl;
    }
    friend double distance(point , point );  
};
double distance(point P1, point P2)
{
    double d=sqrt(pow((P2.x-P1.x),2)+pow((P2.y-P1.y),2));    //sqrt(pow(base,exponent)+pow(base,exponent))
    return d;
}
int main()
{
    int A,B,C,D;
    cout<<"Enter the value of A,B,C and D :- "<<endl;
    cin>>A>>B>>C>>D;
    point p1(A,B);
    p1.display();
    point p2(C,D);
    p2.display();
    double Dis=distance(p1,p2);
    cout<<"Distance between the two points is : "<<Dis<<endl;
    return 0;
}