#include<iostream>
#include<vector>
#include<set>
using namespace std;

void permutation(int idx,string str,set<string> &st){
    //base 
    if(idx==str.size()){
        st.insert(str);
        return;
    }
    for(int j=idx;j<str.size();j++){
        swap(str[idx],str[j]);
        permutation(idx+1,str,st);
        swap(str[idx],str[j]);
    }
}


int main(){
    int idx;
    string s="abc";
    set<string>st;
    
    permutation(0,s,st);
    vector<string> ans(st.begin(),st.end());
    for(const string &s:ans){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}