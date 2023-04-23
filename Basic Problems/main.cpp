#include <iostream>
using namespace std;

int fact(int n){
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
    }
    return factorial;
}


int main()
{   
    cout<<endl;
    int n;
    int r;
    cin>>n>>r;
    int ans=(fact(n)/(fact(n-r)*fact(r)));
    cout<<ans<<endl;
    return 0;
}