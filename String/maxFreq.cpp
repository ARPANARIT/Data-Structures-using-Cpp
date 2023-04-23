#include <iostream>
#include <string>
using namespace std;

char maxFreq(string s){
    int a[26]={0};  //create an index array
    int idx=0;
    for(int i=0;i<s.length();i++){//iterate through the string a,A=0 b,B=1.......z,Z=25
        if(s[i]>='a'&&s[i]<='z'){ //if it is a lower case char
            idx=s[i]-'a';
        }
        else{
           idx=s[i]-'A';//upper case
        }
        a[idx]++; //increment the value at that index in the index array
    }
    int maxi=-1;
    int ans=0;
    for(int i=0;i<26;i++){ //iterate through the index arr to find out which index value has the max 
        if(maxi<a[i]){
            ans=i;
            maxi=a[i];
        }
    }
    char result='a'+ans;
    return result;

}



int main(){
    string s;
    cin>>s;
    cout<<maxFreq(s);
    return 0;
}