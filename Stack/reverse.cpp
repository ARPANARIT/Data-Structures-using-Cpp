#include <iostream>
#include<stack> // library with already defined class
using namespace std;



void reverseSentence(){
 string str="Will never stop loving you";
  stack<string> s;
   for(int i=0;i<str.length();i++){
        string word="";
        while(str[i]!=' ' && i<str.length()){
            word+=str[i];
            i++;
        }
        s.push(word);
   }
   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
   }
   cout<<endl;
}
int main(){
 //  stack<int> s; //define the datatype
  reverseSentence();
  
}

