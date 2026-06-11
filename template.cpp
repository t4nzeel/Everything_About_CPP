#include<iostream>
using namespace std;
template <class T>
class vector{
    public:
    T* arr;
    int size;
    vector(int m){
        size=m;
        arr=new T[size];
    }
    T dotproduct(vector &v){
        T d=0;
        for (int i = 0; i < size; i++)
        {
            d=d+arr[i]*v.arr[i];
        }
        return d;
    }
};
int main(){
    vector<float>v1(2);
    v1.arr[0]=1.4;
    v1.arr[1]=1.2;
    vector<float>v2(2);
    v2.arr[0]=1.3;
    v2.arr[1]=2.5;
    float a=v1.dotproduct(v2);
    cout<<a<<endl;
    return 0;
}