#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++){
        cout<< "Enter your values in array :";
        cin>>a[i];
    }
    int max=a[0];
    for (int i = 1; i < n; i++){
        if(a[i]>max) max=a[i];
    }
    int hash[max+1]={0};  //Initializes each and every position with zero.
    for(int j=0;j<n;j++){
        hash[a[j]]+=1;
    } 
    int q;
    cout<<"Enter ur queries : ";
    cin>>q;
    while(q--){
        int no;
        cin>>no;
        cout<<no<<" has appeared "<<hash[no]<<" times. "<<endl;
    }
    
}