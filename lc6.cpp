#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int s,x,index,mini;
    cout<<"Enter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter ur values : ";
        cin>>x;
        v.push_back(x);
    }
    mini=v[0];                      //mini=*min_element(v.begin(),v.end());    for the finding the minimu value.   
    for(int i=0;i<s;i++){
        if(v[i]<mini){
            mini=v[i];
        }
    }

    auto it=find(v.begin(),v.end(),mini);       //To find the index.
    if(it!=v.end())  index=distance(v.begin(),it);
    reverse(v.begin(),v.begin()+index);
    reverse(v.begin()+index,v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
}