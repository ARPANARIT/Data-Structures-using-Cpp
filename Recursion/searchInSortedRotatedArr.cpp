#include<iostream>
using namespace std;

int Pivot(int a[], int s,int e){
    if(s==e){
        return s;
    }
    int mid=s+(e-s)/2;
    if(a[mid]>=a[0]){
        Pivot(a,mid+1,e);
    }
    else{
        Pivot(a,s,mid);
    }
}

bool BinarySearch(int arr[],int s,int e,int k){
    //base case
    if(s>e) return false;
    int mid=s+(e-s)/2;
    if(arr[mid]==k) return true;
    if(arr[mid]>k){
       BinarySearch(arr,s,mid-1,k);
       
    }
    else{
       BinarySearch(arr,mid+1,e,k);
     
    }
}
// find pivot if element lies within second line update the start to pivot and we already know the end of array so using Binary search find target
// if element lies in first line we already know the start and end will be pivot-1 use BS to find target
bool SearchUisngPivot(int a[],int s,int e,int k){
    int pivot= Pivot(a,s,e);
    //cout<<a[pivot];
    cout<<endl;
    if(k>=a[pivot]&&k<=(e)){
       return BinarySearch(a,pivot,e,k);
    }
    else if (k>=a[0]&&k<=a[pivot-1])
    {
       return BinarySearch(a,0,pivot-1,k);
    }
    return false;
}
int main(){
    int arr[]={7,9,1,2,3};
    int n=5;
    int s=0;
    int e=4;
    cout<<SearchUisngPivot(arr,s,e,19);
}