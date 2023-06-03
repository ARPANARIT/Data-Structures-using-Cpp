#include<iostream>
#include<vector>
using namespace std;
void solve(string str,string output,int index,vector<string> &ans){
    //base case 
    if(index>=str.size()){
        ans.push_back(output);
        return;
    }
     //exclude the character
     solve(str,output,index+1,ans);
     //please include the character please
     char element=str[index];
     output+=element;
     solve(str,output,index+1,ans); 
}


int main(){
    string s="abc";
    vector<string> ans;
    string output="";
    int index=0;
    solve(s,output,index,ans);
    for (const string& val : ans) {
      cout << val << " ";
    }
    return 0;
}