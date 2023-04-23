#include<iostream>
using namespace std;

class Complex{
    private:
    int real;
    int imag;
    public:
    void input(){
        cin>>real;
        cin>>imag;
    }
    Complex operator +(Complex obj){
        Complex temp;
        temp.real=real+obj.real;
        temp.imag=real+obj.imag;
        return temp;
    }
    void output(){
        cout<<"The addition of Two Complex is: ";
        cout<<real<<" +i"<<imag;
    }
};


int main(){
    Complex com1,com2,res;
    cout<<"Enter first Complex no. ";
    com1.input();
    cout<<"Enter second Complex no. ";
    com2.input();
    res=com1+com2;
    res.output();

    return 0;
}