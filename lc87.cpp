#include<iostream>
using namespace std;
int minBitFlips(int start, int goal){
    int ans=start ^ goal;
    int cnt=0;
    for(int i=0;i<32;i++){
        if(ans&(1<<i)) cnt++;
    }
    return cnt;
}
int main(){
    int s,g;
    cin>>s>>g;
    cout<<minBitFlips(s,g)<<endl;
}