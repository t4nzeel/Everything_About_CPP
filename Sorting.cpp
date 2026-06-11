#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int n,x,mini;
    cout<<"Enter ur size : ";
    cin>>n;
    for (int i = 0; i < n; i++){
        cout<<"Enter ur values : ";
        cin>>x;
        v.push_back(x);
    }

    //Selection sort => Select the minimum and swap.
    
    /*for(int i=0;i<=n-2;i++){
        mini=i;
        for(int j=i;j<=n-1;j++){
            if(v[j]<v[mini]){
                mini=j;
            }
        }
        int temp=v[mini];
        v[mini]=v[i];
        v[i]=temp;
        }*/

    //Bubble Sort => Put the maximum value at the back and swap.
    
    /*for(int i =n-1;i>=0;i--){
        int didSwap=0;
        for(int j=0;j<=i-1;j++){
            if(v[j]>v[j+1]){
                int temp=v[j+1];
                v[j+1]=v[j];
                v[j]=temp;
                didSwap=1;
            }
        }
        if(didSwap==0)  break;
    }*/

    //Insertion Sort => Take the element and place it in its correct position.
    
    /*for(int i=0;i<=n;i++){
        int j=i;
        while(j>0 && v[j-1]>v[j]){
            int temp=v[j-1];
            v[j-1]=v[j];
            v[j]=temp;
            j--;
        }
    }*/
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
}