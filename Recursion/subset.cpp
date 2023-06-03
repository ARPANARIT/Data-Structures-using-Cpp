#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans){
    //base case 
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
     //exclude 
     solve(nums,output,index+1,ans);
     //please include 
     int element=nums[index];
     output.push_back(element);
     solve(nums,output,index+1,ans); 
}


int main(){
   vector<int> arr;
   arr.push_back(1);
   arr.push_back(2);
   arr.push_back(3);
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(arr,output,index,ans);
    for(const vector<int> val:ans){
        for(const int i:val){
            cout<<i;
        }
        cout<<" ";
    }
    cout<<endl;
    return 0;
}