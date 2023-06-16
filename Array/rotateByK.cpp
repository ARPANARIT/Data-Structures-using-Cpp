#include<iostream>
#include<vector>
class Solution{
    public:
    ////// to rotate array by k elements to the right//////////
    void rotateRight(vector<int> &nums,int n,int k){
        vector<int> temp;//////to store the elememts while rotating because dealing with original array overwrites the elements
        k=k%n;
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%n]=nums[i]; //placing each element with added k index so that element moves to the right and for the elements whose index goes beyond range is handled using mod
        }
        //copy the temp back to the original
        nums=temp;
    }
    //////////////////////// to rotate array left by k elements/////////////////
    void rotateLeft(int arr,int n,int k){
        k=k%n;// k = 2
        // ex 1 2 3 4 5
        reverse(arr,arr+k); // reverses first two els 2 1 3 4 5
        reverse(arr+k,arr+n);// reverses last three els  2 1 5 4 3
        reverse(arr,arr+n);// reverse whole 3 4 5 1 2 // this the answer
    }
}