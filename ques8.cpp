#include<iostream>
using namespace std;
void increment(){
    static int i=1;
    cout<<i<<"\n";
    i++;
}
int main(){
    increment();
    increment();
    increment();
}