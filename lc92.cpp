#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool isNStraightHand(vector<int>& hand, int groupSize){
    if(hand.size()%groupSize!=0)  return false;
    map<int,int>freq;
    for(int x:hand) freq[x]++;
    while(!freq.empty()){
        int start=freq.begin()->first;
        for(int i=0;i<groupSize;i++){
            int card=start+i;
            if(freq[card]==0) return false;
            freq[card]--;
            if(freq[card]==0) freq.erase(card);
        }
    }
    return true;
}
int main(){
    vector<int>v={1,2,3,4,5};
    int groupSize=4;
    if(isNStraightHand(v,groupSize)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}