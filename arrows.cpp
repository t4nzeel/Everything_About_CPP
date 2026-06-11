#include<iostream>
using namespace std;
class Complex{
    int r,i;
    public:
    void get_data(){
        cout<<"The real part is "<<r<<endl;
        cout<<"The imaginary part is "<<i<<endl;
    }
    void set_data(int a,int b)
    {
        r=a;
        i=b;
    }
};
int main(){
   // Complex c1;
   // Complex* p=&c1;    this is also valid.
   Complex *p=new Complex;
    //(*p).set_data(1,5);                      By this we are dereferencing the pointer and getting the value.
    //(*p).get_data();
    p->set_data(1,54);
    p->get_data();
    return 0;
}