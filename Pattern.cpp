#include<bits/stdc++.h>
using namespace std;
int main(){
    int cr;
    cout<<"Enter the no. of rows and columns : ";
    cin>>cr;
    for(int i=0;i<(2*cr-1);i++){
        for(int j=0;j<(2*cr-1);j++){
            int top =i;
            int left=j;
            int right=2*cr-2-j;
            int down=2*cr-2-i;
            cout<<(cr-min(min(top,down),min(right,left)))<<" ";  // Here min(---) is used to calculate the minimum distance from the
        }                                                       //  edges , which is later on subtracted from the outer no.. 
        cout<<"\n";
    }
}