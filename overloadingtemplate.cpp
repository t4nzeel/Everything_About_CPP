#include<iostream>
using namespace std;
template<class T>
class Tanz{
    public:
    T data;
    Tanz(T a){
        data=a;
    }
    void display();
};
template<class T>
void Tanz<T>::display(){
    cout<<data;
}
void func(int a){             //Since exact function will execute first.
    cout<<"I am first finction."<<a<<endl;
}
template<class T>             //To define T before use.
void function(T a){
    cout<<"I am template function."<<a<<endl;
}
int main(){
    func(5);
    Tanz<double> T1(7.56432);
    T1.display();
    return 0;
}