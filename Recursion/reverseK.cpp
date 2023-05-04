#include<iostream>
using namespace std;
//reverse array in groups of K elements
//eg 1 2 3 4 5 6 7 8 9 10 11  ->  3 2 1 6 5 4 9 8 7 11 10
void reverseKgroup(int arr[],int k,int n){
// you need to find the first and last index for which recursion will be called
    for(int i=0;i<n-1;i=i+k){//i=i+k is the start of every group
        int left=i;
        int right =i+k-1;//this is the last index of every k group
        if(right>n-1)  right=n-1;//corner case where I dont have k elements to reverse
        while(left<=right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    return;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    reverseKgroup(arr,3,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
