#include<iostream>
using namespace std;

   /*
    |   
    |     /\ <- peak 
    |    /  \
    |   /    \   
    |  /      \
    |_________________________   

    first line follows a[mid]<a[mid+1]
    second line follows a[mid]<a[mid+1]
    so accordingly update the start and end to come close to peak
   */ 
int PeakIndex(int a[],int s,int e){
    if(s==e) return s;
    int mid=s+(e-s)/2;
    if(a[mid]<a[mid+1]) PeakIndex(a,mid+1,e);
    else{
        PeakIndex(a,s,mid);
    }
}
int main(){
    int arr[]={0,10,15,2,1};
    cout<<"Peak Index: "<<PeakIndex(arr,0,4)<<" Peak element: "<<arr[PeakIndex(arr,0,3)];
}