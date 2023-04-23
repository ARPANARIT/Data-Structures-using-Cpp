#include <iostream>
using namespace std;

int minimum(int a,int b,int c){
    int min;
    if(a<b){
        if(a<c){
            min=a;
        }
        else{
            min=c;
        }
    }
    else{
        if(b<c){
            min=b;
        }
        else{
           min=c;
        }
    }
    return min;
}
int main(){
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
  int  mini=minimum(a,b,c);
   
    cout<<mini;
    return 0;
}
