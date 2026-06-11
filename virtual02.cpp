#include<iostream>
#include<cstring>
using namespace std;
class Tanz{
    protected:
    string t;
    float ra;
    public:
    Tanz(string s,float r){
        t=s;
        ra=r;
    }
    virtual void display(){}
};
class Tanz1:public Tanz{
    float v;
    public:
    Tanz1(string s,float r,float vl):Tanz(s,r){
        v=vl;
    }
        void display(){
            cout<<t<<endl;
            cout<<ra<<endl;
            cout<<v<<endl;
        }        
    };
    class Tanz2:public Tanz{
        int w;
        public:
        Tanz2(string s,float r,int wc):Tanz(s,r){
            w=wc;
        }
        void display(){
            cout<<t<<endl;
            cout<<ra<<endl;
            cout<<w<<endl;
        }
    };
    int main(){
        string t;
        float r,v;
        int w;
        t="Tanzeel Arshad";
        v=4.56;
        r=4.89;
        Tanz1 qwer(t,r,v);
        
    }

