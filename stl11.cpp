#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printDivisors(int x){
    vector<int>v;
    for(int i=1;i*i<=x;i++){     //Equivalent to i<=sqrt(n).
        if(x%i==0){
            v.push_back(i);
        if((x/i)!=i){
            v.push_back(x/i);
        }
    }
    }
    sort(v.begin(),v.end());
    for(auto it : v)  cout<<it<<"  ";        //alternative for: for(auto it=v.begin();it<=v.end();it++){
}                                           //                           cout<<*it<<" "; }
int main(){
    int n;
    cout <<"Enter ur no. : ";
    cin>>n;
    printDivisors(n);
}