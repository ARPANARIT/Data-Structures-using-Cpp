#include<iostream>
using namespace std;

void print(int mid){
    cout<<"MID: "<<mid<<endl;
}
int SquareRoot(int s,int e,int n){
    if(e<s) return e;
    int mid=s+(e-s)/2;
   // print(mid);
    int sq=mid*mid;;
    if(sq==n) return mid;
    if(sq<n) {
        SquareRoot(mid+1,e,n);
    }
    else{
        SquareRoot(s,mid-1,n);
    }
}
int precision(int n,int prec,int temp){
    double factor=1;
    double ans=temp;
    for(int i=0;i<prec;i++){
        factor=factor/10;
        for(int j=temp;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}
int main(){
    int n=37;
    int s=0;
    int e=n;
    int res=SquareRoot(s,e,n);
    cout<<precision(n,3,res);
}