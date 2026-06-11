#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>l;
    int x;
    for (int i = 0; i < 7; i++){
        cout<<"Enter ur values :";
        cin>>x;
        l.push_back(x);
    }
    //l.unique();        Will remove all the duplicate ones leaving behind their first occurence and others.
    l.remove(3);       //Removes all the elemengts with same value.
    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++){
        cout<<*it<<" ";
    }
}