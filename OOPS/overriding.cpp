#include<iostream>
using namespace std;

class Base{
    public:
     void print(){ // dynamically binds the address of child class to the base class while runtime.
        cout<<"Print function of Base class"<<endl;
    }
    void display(){
        cout<<"Display function of Base class"<<endl;
    }
};
class Child:public Base{
    public:
   virtual void print(){
        cout<<"Print function of Child class"<<endl;
    }
    virtual void display(){
        cout<<"Display function of Child class"<<endl;
    }
};

int main(){
    Base *base;
    Child child;
    base=&child;
    base->display();
    base->print();
    return 0;
}