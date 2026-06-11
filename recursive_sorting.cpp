#include<iostream>
#include<vector>
using namespace std;

//Recursive bubble sort

/*void bubble_sort(vector<int>&v,int n){
    if(n==1)  return;
    int didSwap=0;
    for(int j=0;j<=n-2;j++){
        if(v[j]>v[j+1]){
            int temp=v[j+1];
            v[j+1]=v[j];
            v[j]=temp;
            didSwap=1;
        }
    }
    if(didSwap==0)  return;
    bubble_sort(v,n-1);
}*/

//Recursive Insertion sort

/*void insertion_sort(vector<int>&v,int i,int n){
    if(i==n)return ;
    int j=i;
    while(j>0 && v[j-1]>v[j]){
        int temp=v[j-1];
        v[j-1]=v[j];
        v[j]=temp;
        j--;
    }
    insertion_sort(v,i+1,n);
}*/

int main(){
    vector<int>v1;
    int s,x,i=0;
    cout<<"Enter size : ";
    cin>>s;
    for(int i=0;i<s;i++){
        cout<<"Enter ur value : ";
        cin>>x;
        v1.push_back(x);
    }
    //bubble_sort(v1,s);
    //insertion_sort(v1,i,s);
    for (int i = 0; i < v1.size(); i++){
        cout<<v1.at(i)<<" ";
    }
    
}