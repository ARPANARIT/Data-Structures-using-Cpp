#include<iostream>
using namespace std;
// ex arr 7,9,1,2,3  pivot is 1
//how if you plot it on graph you will see two lines 
// 1. 7-9 and 2. 1-3
/*
    |   9/
    |   /
    |7 / <- 0th index
    |
    |          3  / <- n-1th index
    |         2  /
    |        1  / <-pivot
    |_________________________    

calc mid if a[mid]>=a[0] then increment s so that you can jump to second line to search pivot 

*/
int Pivot(int a[],int s,int e){
    while(s<e){
        int mid=s+(e-s)/2;
        if(a[mid]>=a[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return e;
}
int main(){
    int arr[]={5,61,2,3,4,5};
    cout<<"Pivot Index: "<<Pivot(arr,0,5)<<" Pivot element: "<<arr[Pivot(arr,0,5)];
}