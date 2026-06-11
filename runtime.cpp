#include<iostream>
using namespace std;
class B{
    public:
    int v1;
    void display(){
        cout<<"Displaying base class variable "<<v1<<endl;
    } 
};
class D : public B{
    public:
    int v2;
    void display(){
        cout<<"Displaying base class variable "<<v1<<endl;
        cout<<"Displaying base derived variable "<<v2<<endl;
    }
};
int main(){
    B * bp;
    B ob;
    D od;
    bp=&od;   //pointing base class pointer to derived class.
    bp->v1=32;  //bp->v2=31 will show an error.   Compiler only knows *B and v2 is not present in classD.
    bp->display();  //Late binding    will refer to the display()in Class B.
    D * dp;
    dp=&od;
    dp->v2=98;
    dp->display();  // Will refer to the dsiplay() in classD as now pointer for derived has been made.
    return 0;
}
//It is not necessary to use pointer we can simply use object created by the constructor.