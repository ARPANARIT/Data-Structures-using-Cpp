#include <iostream>
using namespace std;

int product(int m,int n){
    int product=m*n;
    return product;
}


int main(){
    int a,b;
    cin>>a>>b;
    cout<<product(a,b);
    return 0;
}