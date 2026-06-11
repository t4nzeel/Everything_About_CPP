#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>a,b;
    int x,y;
    for (int i = 0; i < 7; i++){
        cout<<"Enter ur element :";
        cin>>x;
        a.push_back(x);
    }
    for (int i = 0; i < 5; i++){
        cout<<"Enter ur element :";
        cin>>y;
        b.push_back(y);
    }
    a.swap(b);
    for (int i = 0; i < a.size(); i++){         //size() is used because after swapping size is changed therefore in order to get the updated size it is used
        cout<<a.at(i)<<" ";
    } 
    cout<<"\n";
    for (int i = 0; i < b.size(); i++){        //size() is used because after swapping size is changed therefore in order to get the updated size it is used
        cout<<b.at(i)<<" ";
    }  
    return 0;
}