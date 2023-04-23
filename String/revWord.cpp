#include <string>
#include <iostream>
using namespace std;

string reverseString(string s){
  int n=s.length();
  string result;
  int j,k;
  for(int i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(s[j]==' '){
        j++;
      }
      break;
    }
    
    for(k=j+1;k<n;k++){
      if(s[k]!=' '){
        k++;
      }
      break;
    }
    string sub=s.substr(j,k-j);
    if(result.length()==0) result=sub;
    else {result=sub+" "+result;}
    j=k+1;
  }
    return result;
}
int main(){
  string s;
  cin>>s;
  cin.ignore();
  string reverse=reverseString(s);
  cout<<reverse;
  return 0;
}

