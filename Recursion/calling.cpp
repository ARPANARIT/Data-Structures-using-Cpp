#include<iostream>
using namespace std;


void print(int n){
    if(n==0) return;
    cout<<n<<" ";//first print then call
    print(n-1);
    cout<<n<<" ";//print after return of the call
}

int main(){
    print(5);
    return 0;
}