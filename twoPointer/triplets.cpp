#include<iostream>
#include<algorithm>
using namespace std;

int findTriplets(int arr[5],int n){
    int x=0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int low=i+1;
        int high=n-1;
        while(low<high){
            int curr=arr[i]+arr[low]+arr[high];
        if(curr==x){
            return 1;
        }
        if(curr<x){
            low++;
        }
        else{
            high--;
        }
        }
    }
    return -1;
}
int main(){
    int arr[5]={0,1,-1,3,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<findTriplets(arr,n);
}