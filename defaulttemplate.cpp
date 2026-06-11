#include<iostream>
using namespace std;
template<class T1=int,class T2=float>
class Tanz{
    T1 a;
    T2 b;
    public:
    Tanz(T1 x,T2 y){
        a=x;
        b=y;
    }
    void display(){
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
    }
};
int main(){
    Tanz<> t(2,4.56);     //Since no data type was mentioned therefore default data type was taken i.e.,float and int. 
    t.display();
    Tanz<char,string>g('A',"Tanzeel Arshad"); //Was able to happen because I have provided the data types in Tanz<>. 
    g.display();
    return 0;
}