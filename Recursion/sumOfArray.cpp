#include<iostream>
using namespace std;

void print(int arr[],int size){
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int sumofarray(int arr[],int size){

    print(arr,size);
    if(size==1){
        return arr[0];
    }
    return arr[0]+sumofarray(arr+1,size-1);
}




int main(){
    int arr[]={3,2,5,1,6};
    int size=5;
    int result=sumofarray(arr,size);
    cout<<result<<endl;
    return 0;
}