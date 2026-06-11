#include<iostream>
#include<cmath>
using namespace std;
class Simplecalculator
{
    protected:
    double a,b;
    public:
    void input(double,double);
    void outputs(void);
};
void Simplecalculator::input(double x,double y)
{
    a=x;
    b=y;
}
void Simplecalculator::outputs()
{
    int z;
    cout<<"Press 1 for +,press 2 for -,press 3 for *,press 4 for / ."<<endl;
    cin>>z;
    switch (z)
    {
    case 1:
        cout<<"Sum of ("<<a<<" + "<<b<<") is "<<(a+b)<<endl;
        break;
    case 2:
        cout<<"Difference of ("<<a<<" - "<<b<<") is "<<(a-b)<<endl;
        break; 
    case 3:
        cout<<"Product of ("<<a<<" x "<<b<<") is "<<(a*b)<<endl;
        break;
    case 4:
        double z1;
        z1=a/b;
        cout<<"Quotient of ("<<a<<" / "<<b<<") is "<<z1<<endl;
        break;        
    default:
        cout<<"Error!!!!"<<endl;
        break;
    }
}
class Scientific
{
    protected:
    double i,o;
    public:
    void in(double x, double y)
    {
        i=x;
        o=y;
    }
    void out()
    {
        int p;
        cout<<"Press 1 for square root of 1st no.,press 2 for square root of 2nd no.,press 3 for cube root of 1st no.,press 4 for cube root of 2nd no. ."<<endl;
        cin>>p;
        switch (p)
        {
        case 1:
            cout<<(sqrt(i))<<endl;
            break;
        case 2:
            cout<<(sqrt(o))<<endl;
            break; 
        case 3:
            cout<<(cbrt(i))<<endl;
            break;
        case 4:
            cout<<(cbrt(o))<<endl;
            break;        
        default:
            cout<<"Error!!!!"<<endl;
            break;
        } 
    }
};
class hybrid: public Simplecalculator,public Scientific   //Multiple inheritance
{
    public:
    void set(double x1,double x2)
    {
        Simplecalculator::input(x1,x2);
        Simplecalculator::outputs();
        Scientific::in(x1,x2);
        Scientific::out();
    }
};
int main()
{
    double y1,y2;
    cout<<"Enter your 2no.s respectively :-"<<endl;
    cin>>y1>>y2;
    hybrid tanz;
    tanz.set(y1,y2);
}