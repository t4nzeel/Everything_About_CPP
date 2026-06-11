#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int s,x;
    cout<<"Enter size of vector: ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur element : ";
        cin>>x;
        v.push_back(x);
    }
    vector<int>::iterator l=v.begin();
    v.erase(l,l+2);
    v.insert(l,2,5);
    for (int i = 0; i < v.size(); i++){
        cout<<v.at(i)<<" ";
    }  
}