#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>mp;
    string s;
    int n,m;
    cout<<"Enter the no. of students :";
    cin>>n;
    for(int i =0;i<n;i++){
        cout<<"Enter the name and their respective marks :";
        cin>>s>>m;
        mp[s]=m;//
    }
    //mp.insert({{"Dastagir",21},{"Shayan",15}});
    //map<string,int>::iterator itr;
    //itr=mp.find("Tanzeel");
    //mp.erase(itr);
    map<string,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){    //Print the data stored in associative array.
        cout<<(*it).first<<" => "<<it->second<<endl;       //Here first and second are the pointers to the respective key and value.

    }
}