#include<bits/stdc++.h>
using namespace std;

class Content{
    public:
    virtual void produce()=0;
    virtual ~Content(){};
};
class BlogPost: public Content{
public: 
 void produce() override{
    cout<<"producing blogPost."<<endl;
 }
};
class Video: public Content{
public: 
 void produce() override{
    cout<<"producing Video."<<endl;
 }
};
class Infographic: public Content{
public: 
 void produce() override{
    cout<<"producing Infographic."<<endl;
 }
};
class ContentFactory {
    public: 
    static Content* returnContent(string contentType){
        for (auto &c : contentType) {
            c = tolower(c);
        }
        if(contentType=="blogpost"){
            return new BlogPost();
        }else if(contentType=="video"){
            return new Video();
        }else if(contentType=="infographic"){
            return new Infographic();
        }else {
            cout<<"Enter valid content Type"<<endl;
            return nullptr;
            
        }
    }
};
int main(){
    string contentType;
    cout<<"Enter contentTYpe:"<<endl;
    cin>>contentType;

    Content* post=ContentFactory::returnContent(contentType);
    
    if (post) { // Safety check
        post->produce();
        delete post; // Cleanup
    }
    return 0;
}