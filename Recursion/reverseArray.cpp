#include<iostream>
using namespace std;
//reverse an array
//strategy :
//          call the function with arr, start index, total no. of elements
//          if start index crosses the middle of the length of array then simply return
//           swap the content of first and last index
//           recursively call for the next index
void reverseArr(int a[],int i,int n){
    if(i>=n/2) return;
    swap(a[i],a[n-i-1]);
    return reverseArr(a,i+1,n);
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    reverseArr(arr,0,n);
    for(int j=0;j<n;j++) cout<<arr[j]<<" ";
}