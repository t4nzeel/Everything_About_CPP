#include<iostream>
using namespace std;
class B{
    public:
    int v1=1;
    virtual void display(){
        cout<<"Displaying base class variable "<<v1<<endl;
    } 
};
class D : public B{
    public:
    int v2=2;
    void display()override{                  //Override keyword can be written.
        cout<<"Displaying base class variable "<<v1<<endl;
        cout<<"Displaying base derived variable "<<v2<<endl;
    }
};
int  main(){
    B * bp;
    B ob;
    D od;
    bp=&od;
    bp->display();
    return 0;
}