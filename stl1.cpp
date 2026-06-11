#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x;
    vector<int> v;          //Enables manipulative size of array.
    for(int i=0;i<5;i++){
        cout<<"Enter ur ele :";
        cin>>x;
        v.push_back(x);
    }
    v.pop_back();
    vector<int>::iterator it=v.end();    //Iterators used here are used to traverse in a vector array.
    v.insert(it-2,10,100);
    for (int i = 0; i < v.size(); i++)  //i<5 is incorrected because v[4] is undefined after pop_back().
    {
        cout<<v[i]<<"  ";
        //cout<<v.at(i)<<" ";      v.at(i)=v[i]   Both are same thing.
    }
    return 0;
}