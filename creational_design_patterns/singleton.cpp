#include<bits/stdc++.h>
using namespace std;

class Singleton{
private:
 static Singleton* instance;
 Singleton(){
    cout<<"Singleton class constructor called. New obj created"<<endl;
 }
 public:
 static Singleton* getInstance(){
    if(instance==nullptr){
        instance=new Singleton();
    }
    return instance;
 }
};
Singleton* Singleton::instance=nullptr;
int main(){
    Singleton* s1=Singleton::getInstance();
    Singleton* s2=Singleton::getInstance();
    cout<<(s1==s2)<<endl;
    return 0;
}