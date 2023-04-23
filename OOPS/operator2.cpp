#include<iostream>
using namespace std;

class Complex{
    private:
    int real,imag;
    public:
    Complex(int r,int i){
        real=r;
        imag=i;
    }
    Complex(){}
    Complex operator +(Complex obj){
        Complex tem;
        tem.real=real+obj.real;
        tem.imag=imag+obj.imag;
        return tem;
    }
    void display(){
        cout<<real<<" +i"<<imag;
    }
};
int main(){
    Complex c1(2,30),c2(1,6);
    Complex c3=c1+c2;
    c3.display();
    return 0;
}