#include<iostream>
using namespace std;
template<class T1=int,class T2=float>
float average(T1 a,T2 b){
    float avg=(a+b)/2.0;
    return avg;
}
template<class T>
void swapp(T &c,T &d){           //Reference variables were used.
    T temp=c;
    c=d;
    d=temp;
}
int main(){
    float a=average(5,3.2);
    cout<<a<<endl;
    int x=7,y=5;
    swapp(x,y);
    cout<<x<<endl<<y<<endl;
    return 0;
}