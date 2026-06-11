#include<iostream>
using namespace std;
class A{
    int a;
    public:
    A& setData(int a){
        this->a=a;   //This tells compiler to assign arg a to the this->a.
        return *this;   //Since the setData return type is A&.Therefore, this enables method chaining i.e.,it returns 4 as an object.
    }
    void getdata(){
        cout<<"The value of a is "<<a<<endl;
    }
};
int main(){
    A a;
    a.setData(4).getdata();//Since the setdata() function returning 4 as an object therefore getdata() can also be written in same line. 
} 
//Method chaining is only allowed if the previous function returns value as an object.  