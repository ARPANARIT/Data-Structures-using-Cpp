#include<iostream>
using namespace std;


bool LinearSearch(int *arr,int size,int k){
    if(size==0) return false;
    if(arr[0]==k) return true;
    return LinearSearch(arr+1,size-1,k);
}

int main(){
    int a[]={1,2,3,4,5};
    bool ans=LinearSearch(a,5,8);
    cout<<ans;

}