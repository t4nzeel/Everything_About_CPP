#include<iostream>
using namespace std;
template<class T1, class T2>
class Tanz{
    public:
    T1 data1;
    T2 data2;
    Tanz(T1 a,T2 b){
        data1=a;
        data2=b;
    }
    void display(){
        cout<<data1<<endl<<data2;
    }
};
int main(){
    Tanz<char,float>ob('T',4.0); //Important line.
    ob.display();
    return 0;
}