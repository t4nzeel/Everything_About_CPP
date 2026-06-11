#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swapnums(vector<int>V1,int i1,vector<int>V2,int i2){
    if(V1[i1]>V2[i2]) swap(V1[i1],V2[i2]);
}
int main(){
    int s1,x1,s2,x2;
    cout<<"Enter sizes : ";
    cin>>s1>>s2;
    vector<int>v1,v2;
    for(int i=0;i<s1;i++){
        cout<<"Enter value : ";
        cin>>x1;
        v1.push_back(x1);
    }
    for(int i=0;i<s2;i++){
        cout<<"Enter value : ";
        cin>>x2;
        v2.push_back(x2);
    }
    /*int j=0;
    for(int i=0;i<max(s1,s2);i++){
        if(v1[i]<v2[j] && v1[i]!=0) continue;
        else if(v1[i]>v2[j]) swap(v1[i],v2[j]);
        else if(v1[i]==v2[j] && v1[i]!=0) swap(v1[i+1],v2[j]);
        else if(v1[i]==0){
            swap(v1[i],v2[j]);
            j++;
        }
    }
    for (int i = 0; i < max(s1,s2); i++){
        cout<<v1[i]<<"  ";
    }*/
    int len=s1+s2;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            if(left<s1 && right>=s1) swapnums(v1,left,v2,right-s1);
            else if(left>=s1)  swapnums(v1,left-s1,v2,right-s1);
            else swapnums(v1,left,v2,right);
            left++; right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";
}