#include <iostream>
using namespace std;

int minJump(int a[],int st,int en){
    if(st==en){
        return 0;
    }
    int count=INT64_MAX;
    for(int i=1;(i<a[st]&&i<en);i++){
        int jumpCount=1+minJump(a,st+i,en);
        if(jumpCount<count){
            count=jumpCount;
        }
    }
    return count;}
int main(){
    int arr[11]={1,3,5,8,10,2,6,7,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int start=arr[0];
    int end=arr[n-1];

    int minJump_count=minJump(arr,start,end);
    cout<<"Min Jump to reach end "<<endl;
    cout<<minJump_count;
    return 0;
}