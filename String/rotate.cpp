#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool rotate(string s,string str){
    while(s.length()!=0){
       char* found= strstr(s.c_str(),str.c_str());
            if(found) return true;
        }
    }




int main(){
    string s,str;
    cin>>s>>str;
    cout<<rotate(s,str);

    return 0;
}