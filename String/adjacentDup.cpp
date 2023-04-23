#include<iostream>
#include<string>
using namespace std;

string removeDuplicate(string s){
    int i=0;
    string result="";
    while(s[i]){
        if(s[i]!=s[i+1]){
          result =result+s[i];
            i++;
        }
        if(s[i+1]&&s[i]==s[i+1]){
            // skip through all the chars which are same
            while(s[i]==s[i+1]){
                i++;
            }
        }
        i++;
    }
    return result;

}
int main(){
    string s;
    cin>>s;
    cout<<removeDuplicate(s);
    return 0;
}