#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int x,max;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    max=*max_element(v.begin(),v.end());
    cout<<max;
    return 0;
}