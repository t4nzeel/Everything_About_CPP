#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>l1,l2;
    l1={7,3,2,1,4,2};
    l2={3,1,2};
    //l1.sort();
    //l2.sort();
   //l1.merge(l2);
   //l1.sort();
    l1.swap(l2);
    list<int>::iterator it;
    for(it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }
}