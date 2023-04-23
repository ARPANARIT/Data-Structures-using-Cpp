#include <iostream>
#include <string>

using namespace std;

int tolowerCase(char ch){
    if(ch>='a' && ch<='z'){return ch;}
    else{
        ch=ch-'A'+'a';
        return ch;
    }
}

int strlength(char str[]){
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        count++;
    }
    return count;
}
int isPalindrome( char str[],int n){
    for(int i=0;i<str[i]!='\0';i++){
        if(tolowerCase(str[i])!=tolowerCase(str[n-1-i])){
            return 0;
        }
    }
    return 1;
}



int main()
{
    char ch[10];
    cin>>ch;
    int len=strlength(ch);
    if(isPalindrome(ch,len)){
        cout<<ch<<" is Palindrome."<<endl;
    }
    else{
        cout<<ch<<" not a Palindrome."<<endl;
    }
    
    
    return 0;
}
