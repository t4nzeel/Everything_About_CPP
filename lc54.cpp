#include<iostream>
#include<cctype>
#include<string>
#include<climits>
using namespace std;
int  myAtoi(string s1){
   if(s1.length()==0) return 0;
   int i=0;
   while(i<s1.size() && s1[i]==' ') i++;
   s1=s1.substr(i);
   int sign=1;
   long long ans=0;
   if(s1[0]=='-') sign=-1;
   int maxi=INT_MAX,mini=INT_MIN;
   i=(s1[0]=='+' || s1[0]=='-') ? 1:0;
   while(i<s1.size()){
    if(s1[0]==' ' || !isdigit(s1[i])) break;
    ans=(ans*10)+(s1[i]-'0');
    if(sign==-1 && -1*ans<mini) return mini;
    if(sign==1 && ans>maxi) return maxi;
    i++;
   }
   return (int)(sign*ans); 
}
int main(){
    string s;
    cout<<"Enter : ";
    cin>>s;
    cout<<myAtoi(s);
}