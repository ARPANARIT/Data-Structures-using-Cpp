#include<iostream>
#include<string>
using namespace std;

string removeOccurence(string s,string part){
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){
    
    string s="ababababARpana";
    //cin>>s;
    //int l=s.length();
    string part="ab";
    cout<<removeOccurence(s,part);
    
    
    return 0;}