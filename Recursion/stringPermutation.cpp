#include<iostream>
#include<vector>
using namespace std;

void solve(string digit, string output, int index, vector<string>&ans, string map[]){
    //base 
    if(index>=digit.length()){
        ans.push_back(output);
        return;
    }
    int num=digit[index]-'0';
    //alphabets mapped to the digit
    string val=map[num];
    for(int i=0;i<val.length();i++){
        output.push_back(val[i]);
        solve(digit,output,index+1,ans,map);
        output.pop_back();
    }
}

int main(){
    string digit="23";
    int index=0;
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string output="";
    solve(digit,output,index,ans,map);
    for(const string &i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
