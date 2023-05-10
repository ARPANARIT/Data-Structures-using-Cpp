#include<iostream>
using namespace std;

void print(int a[],int s,int e){
    for(int i=s;i<e;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool BinarySearch(int arr[],int s,int e,int k){
    //base case
    print(arr,s,e);
    if(s>e) return false;
    int mid=s+(e-s)/2;
    if(arr[mid]==k) return true;
    if(arr[mid]>k){
       BinarySearch(arr,s,mid-1,k);
       // BinarySearch(arr,mid+1,e,k);// for decreasing order
    }
    else{
       BinarySearch(arr,mid+1,e,k);
     // BinarySearch(arr,s,mid-1,k);
    }
}

int main(){
    int a[]={60,40,30,20,10};
    cout<<BinarySearch(a,0,5,10);
}