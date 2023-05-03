#include<iostream>
using namespace std;


//this function takes n as input and calls itself recursively by dividing n/2 until n==1;
//this gives the count of how many times n can be divided by 2 before reaching 1;
int func(int n){
    if(n==1){
        return 0;
    }
    return 1+func(n/2);
}
/*recursion tree for n=10
                    func(10) ->1+2=3
                      \
                      func(5) -> 1+1=2
                        \
                        func(2) -> 1+0=1
                           \ 
                           func(1) ->0
                           10/2 = 5, 5/2 = 2, and 2/2 = 1. thus it calls the function 3 times
*/

int main(){
    int n=10;
    func(n);
    return 0;
}