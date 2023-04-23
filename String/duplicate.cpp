#include<iostream>
#include <string>
using namespace std;

string Duplicate(string s){
    int idx[26]={0};
    for(int i=0;i<s.length();i++){
        idx[s[i]-'a']++;
    }
    string ans;
    for(int i=0;i<26;i++){
        if(idx[i]>=2){
            char a=i+'a';
            ans.push_back(a);
           
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<Duplicate(s);
    return 0;
}