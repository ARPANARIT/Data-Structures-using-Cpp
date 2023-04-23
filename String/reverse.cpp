#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    string temp="";
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        temp+=s[i];
    }
    cout<<temp;
    return 0;
}