#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=INT16_MIN;
    int mn=INT16_MAX;
    for(int i=0;i<n;i++){
        if(a[i]>mx){
            mx=max(mx,a[i]);
        }
        if(a[i]<mn){
            mn=min(mn,a[i]);
        }

    }
    cout<<"Max: "<<mx<<" "<<"Min: "<<mn;
    return 0;}