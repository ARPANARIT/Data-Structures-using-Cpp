#include <iostream>
using namespace std;

int calsum(int m, int n, int o){

   int sum=m+n+o;
   return sum;
}

int main(){
    int testcase;
    cin>>testcase;
    while(testcase!=0){
        int a;
        int b;
        int c;
        int sum;
        cin >> a >> b >> c;
        sum = calsum(a, b, c);
        cout << " Sum is: " << sum;
        testcase = testcase - 1;
    }
    return 0;
}
