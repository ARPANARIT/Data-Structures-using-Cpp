#include <iostream>
using namespace std;
int BinarySearch(int arr[],int n, int key){
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    for (int i=0;i<n;i++){
        if(arr[i]==mid){
            return mid;
        }
        if(arr[i]<mid){
            end=mid-1;
        }
        if(arr[i]>mid){
            start=mid+1;
        }
    }
    return -1;
}
 int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int key;
    cin>>key;
    cout<<BinarySearch(array ,n,key);


    return 0;
 }