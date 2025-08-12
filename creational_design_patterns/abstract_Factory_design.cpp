// abstract factory method : Provides an interface (GUIFactory ) for creating families of related objects (ex. WinDesktop and WinButton form one family.) without specifying their concrete classes.

#include<bits/stdc++.h>
using namespace std;


class Desktop {
public:
    virtual void display() =0;
    virtual ~Desktop(){
         cout<<"Deleting Desktop"<<endl;
    };
};

class WinDesktop :public Desktop{
public:
     void display() override{
        cout<<"WinDesktop being displayed"<<endl;
     }
};
class MacDesktop : public Desktop{
public:
     void display() override{
        cout<<"MacDesktop being displayed"<<endl;
     }
};
class Button {
public:
    virtual void display() =0;
    virtual ~Button(){
        cout<<"Deleting button"<<endl;
    };
};
class WinButton :public Button{
public:
     void display() override{
        cout<<"WinButton being displayed"<<endl;
     }
};
class MacButton: public Button {
public:
     void display() override{
        cout<<"MacButton being displayed"<<endl;
     }
};
class GUIFactory{
public:
    virtual Desktop* createDesktop()=0;
    virtual Button* createButton()=0;
    virtual ~GUIFactory(){
        cout<<"Deleting Factory"<<endl;
    }
};
// ek factory se ek family ke related objects bana rahe hain (Mac ke liye MacButton + MacDesktop, Windows ke liye WinButton + WinDesktop).
class WinFactory : public GUIFactory{
public:
Button* createButton()override{
    cout<<"creating WinButton"<<endl;
    return new WinButton();
}
Desktop* createDesktop()override{
     cout<<"creating WinDesktop"<<endl;
    return new WinDesktop();
}
};
class MacFactory:public GUIFactory{
    public:
Button* createButton()override{
     cout<<"creating MacButton"<<endl;
    return new MacButton();
}
Desktop* createDesktop()override{
     cout<<"creating MacDesktop"<<endl;
    return new MacDesktop();
}
};

int main(){
    GUIFactory* factory=new MacFactory;
    // The concrete factories (WinFactory and MacFactory) ensure that when you choose one family, you get matching objects from that family.
    Button* btn=factory->createButton();
    Desktop* dt=factory->createDesktop();

    btn->display();
    dt->display();

    delete btn;
    delete dt;
    delete factory;
    return 0;
}