#include<iostream>
using namespace std;

// Catalan is a series of natural no's. similar to fibonacci
// C(n) = Sum(C(i) * C(n-i-1), i=0 to n-1)
int catalan(int n){
    if(n<=1) return 1;// C0 & C1 =1
    int res=0;
    for(int i=0;i<=n-1;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}

int main(){
    for(int i=0;i<=10;i++){//    C0 C1  C2 C3 C4 C5 C6   C7   C8   C9 C10
        cout<<catalan(i)<<" ";// 1   1  2   5 14 42 132  429 1430 4862 16796 
    }
    return 0;
}