#include<iostream>
using namespace std;

int partition(int arr[],int s ,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);

    //sort elements for pivot's left and right
    int i=s;int j=e;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]<pivot){i++;}
        if(arr[j]>pivot){j++;}
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j]);
        }
    }
    return pivotIndex;
}
void quicksort(int arr[],int s,int e){
    //base case 
    if(s>=e) return;
    int p=partition(arr,s,e);
    //recursive call
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    int arr[]={3,1,5,4,2};
   int n=5;
    quicksort(arr,0,n-1);
    for(int g=0;g<n;g++){
        cout<<arr[g]<<" ";
    }
    cout<<endl;
}