#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int leastInterval(vector<char>& tasks, int n){
    vector<int>freq(26,0);
    for(char &c : tasks) freq[c-'A']++;
    int time=0;
    priority_queue<int>pq;
    for(int i=0;i<26;i++){
        if(freq[i]>0) pq.push(freq[i]);
    }
    while(!pq.empty()){
        vector<int>temp;
        for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }
        for(int &f : temp){
            if(f>0) pq.push(f);
        }
        if(pq.empty()) time+=temp.size();
        else time+=n+1;
    }
    return time;
}
int main(){
    vector<char>v={'A','A','A','B','B','B'};
    int n=2;
    cout<<leastInterval(v,n);
}