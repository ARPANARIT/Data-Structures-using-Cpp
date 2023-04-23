#include <iostream>
#include<string>
using namespace std;

string reverse(string s,int n){
    string result;
    int i=0;
    int j=0;
    while(i<n){
        while(j<n&&s[j]==' '){
            j++;
        }
        int k=j+1;
        while(k<n&&s[k]!=' '){
            k++;
        }
        string word=s.substr(j,k-j);
        if(result.length()==0){
            result=word;
        }
        else{
            result=result+" "+word;
        }
        if(s[i]=='\0') break;
        else{i++;}
    }
    return result;
}

int main(){
    string s;
    int len=s.length();
    cout<<reverse(s,len)<<endl;
    return 0;
}