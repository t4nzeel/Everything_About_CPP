#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;
int Anti_Roman(string s1){
    /*int c=0,n=0,r;
    for(auto it=s1.begin();it!=s1.end();it++){
        if(*it=='I'){
            n+=1;
            c=1;
        }
        else if(*it=='V'){
            if(c<5){
               r=5-(2*c);
               n+=r;
               c=5; 
            }
            else {n+=5; c=5;}
        }
        else if(*it=='X'){
            if(c<10){
               r=10-(2*c);
               n+=r;
               c=10; 
            }
            else {n+=10; c=10;}
        }
        else if(*it=='L'){
            if(c<50){
               r=50-(2*c);
               n+=r;
               c=50; 
            }
            else {n+=50; c=50;}
        }
        else if(*it=='C'){
            if(c<100){
               r=100-(2*c);
               n+=r;
               c=100; 
            }
            else {n+=100; c=100;}
        }
        else if(*it=='D'){
            if(c<500){
               r=500-(2*c);
               n+=r;
               c=500; 
            }
            else {n+=500; c=500;}
        }
        else if(*it=='M'){
            if(c<1000){
               r=1000-(2*c);
               n+=r;
               c=1000; 
            }
            else {n+=1000; c=1000;}
        }
    }
    return n;*/
    unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int n=0;
    for(int i=0;i<s1.size();i++){
        if(i+1<s1.size() && m[s1[i]]<m[s1[i+1]]) n-=m[s1[i]];
        else n+=m[s1[i]];
    }
    return n;
}
int main(){
    string s;
    cout<<"Enter : ";
    cin>>s;
    cout<<Anti_Roman(s);
}