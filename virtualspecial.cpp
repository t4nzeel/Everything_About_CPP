#include<iostream>
using namespace std;
class base1
{
    int d1;
    public:
    base1(int i)
    {
        d1=i;
        cout<<"Base1 constructor called."<<endl;
    }
    void printdatab1(){
        cout<<"The value of data1 is "<<d1<<endl;
    }
};
class base2
{
    int d2;
    public:
    base2(int i)
    {
        d2=i;
        cout<<"Base2 constructor called."<<endl;
    }
    void printdatab2(){
        cout<<"The value of data2 is "<<d2<<endl;
    }
};
class derived: public base1,public base2{
    int der1,der2;
    public:
    derived(int a,int b, int c, int d):base1(a),base2(b){
        der1=c;
        der2=d;
        cout<<"Derived class contructor called."<<endl;
    }
    void printdata(){
        cout<<"The value of der1 is "<<der1<<endl;
        cout<<"The value of der2 is "<<der2<<endl;
    }
};
int main()
{
    derived tanz(1,2,3,4);
    tanz.printdata();        // If only this was written then only derived class printdata() would have been executed.
    tanz.printdatab1();     //   This is because tanz is the object of derived class.
    tanz.printdatab2();
    return 0;
}