#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    vector<int>v,ans;
    int s,x;
    cout<<"Enter size : ";
    cin>>s;
    for (int i = 0; i < s; i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v.push_back(x);
    }
    /*int maxi=*max_element(v.begin(),v.end());
    vector<int>hash(maxi+1,0);
    for(int i=0;i<v.size();i++){
        hash[v[i]]+=1;
    }
    int t=v.size()/3;
    for(int i=0;i<=maxi;i++){
        if(hash[i]>t)  ans.push_back(i);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }*/
   int c1=0,c2=0;
   int e1=INT_MIN;
   int e2=INT_MIN;
   for(int i=0;i<v.size();i++){
    if(c1==0 && e2!=v[i]){
        c1=1;
        e1=v[i];
    }
    else if(c2==0 && e1!=v[i]){
        c2=1;
        e2=v[i];
    }
    else if(e1==v[i]) c1++;
    else if(e2==v[i]) c2++;
    else{
        c1--;
        c2--;
    }
   }
   vector<int>ls;
   c1=0,c2=0;
   for(int i=0;i<v.size();i++){
    if(e1==v[i])  c1++;
    if(e2==v[i])  c2++;
   }
   int mini=(int)(v.size()/3);
   if(c1>mini) ls.push_back(e1);
   if(c2>mini) ls.push_back(e2);
   sort(ls.begin(),ls.end());
   for(int i=0;i<ls.size();i++){
    cout<<ls.at(i)<<" ";
   }
   return 0;
}