#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string>st(wordList.begin(),wordList.end());
    queue<pair<string,int>>q;
    q.push({beginWord,1});
    st.erase(beginWord);
    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==endWord)return steps;
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }
    return 0;
}
int main(){
    string a,b;
    cin>>a>>b;
    vector<string>v={"hot","dot","lot","log","cog"};
    cout<<ladderLength(a,b,v)<<endl;
}