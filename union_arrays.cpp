#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v1,v2,u;
    int s1,s2,x1,x2;
    cout<<"Enter sizes respectively : ";
    cin>>s1>>s2;
    for(int i=0;i<s1;i++){
        cout<<"Enter ur values in 1st : ";
        cin>>x1;
        v1.push_back(x1);
    }
    for(int i=0;i<s1;i++){
        cout<<"Enter ur values in 2nd : ";
        cin>>x2;
        v2.push_back(x2);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i=0,j=0;
    int n1=v1.size();
    int n2=v2.size();
    while(i<n1 && j<n2){
        if(v1[i]<=v2[j]){
            if(u.size()==0 || u.back()!=v1[i]){
                u.push_back(v1[i]);
            }
            i++;
        }
        else {
           if(u.size()==0 || u.back()!=v2[j]){
                u.push_back(v2[j]);
            }
            j++; 
        }
    }
    while(j<n2){
        if(u.size()==0 || u.back()!=v2[j]){
            u.push_back(v2[j]);
            }
        j++;
    }
    while(i<n1){
        if(u.size()==0 || u.back()!=v1[i]){
            u.push_back(v1[i]);
        }
        i++;
    }
    for (int i = 0; i <u.size(); i++){
        cout<<u.at(i)<<" ";
    }
    
}