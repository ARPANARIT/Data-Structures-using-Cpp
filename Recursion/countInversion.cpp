#include<iostream>
using namespace std;
int merge(int a[],int temp[],int s,int e,int m){
    int i,j,k;
    int inv_count=0;
    i=s;
    j=m+1;
    k=s;
    while(i<=m && j<=e){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            inv_count+=m-i;//the two halves are sorted so if a[i]>a[j] then all the elememts in the first half are greater than the first in the a[j] so count of inversion are all the elements in the first half denoted by m-i
            temp[k++]=a[j++];
        }
    }
    while (i<=m)
    {
        temp[k++]=a[i++];
    }
    while (j<=e)
    {
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i++]=temp[i++];
    }
    return inv_count;
}
int utilmergeSort(int a[],int temp[],int s,int e){
    int mid, countInv=0;
    
    while(e>s){
        mid=s+(e-s)/2;
        countInv+=utilmergeSort(a,temp,s,mid);
        countInv+=utilmergeSort(a,temp,mid+1,e);
        countInv+=merge(a,temp,s,e,mid);
    }
    return countInv;
}
int mergeSort(int a[],int size){
    int temp[size];
    return utilmergeSort(a,temp,0,size);
}
int main(){
    int arr[]={2,3,1,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=mergeSort(arr,n);
    cout<<"Inversion count: "<<count<<endl;
}