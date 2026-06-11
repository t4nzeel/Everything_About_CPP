#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>l;
    int s,x;
    cout<<"Enter the size :";
    cin>>s;
    for (int i = 0; i < s; i++)
    {
        cout<<"Enter ur values :";
        cin>>x;
        //l.push_back(x);            1 2 3 4 5 
        l.push_front(x);           //5 4 3 2 1 
    }
    //list<int>::iterator itr1=l.begin(),itr2=l.begin();
    //advance(itr2,2);    //Advances the iterator by 2 steps.
    //l.erase(itr1,itr2);
    l.sort();
    l.reverse();
    list<int>::iterator it;
    for (it=l.begin(); it!=l.end(); it++)   //To print list.
    {
        cout<<*it<<" ";       //*itr prints the value store at that pointer.
    }
}