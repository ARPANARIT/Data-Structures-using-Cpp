#include<iostream>
#include <string>
using namespace std;

bool checkEqual(int a[26],int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return false;
        }
        return true;
    }
}   
bool permutation(string s1, string s2){
    int count1[26]={0};
    for(int i=0;i<s1.length();i++){
        count1[s1[i]-'a']++;
    }
    int windowSize=s1.length();
    int count2[26]={0};
    int i=0;
    while(i<windowSize){
        count2[s2[i]-'a']++;
        i++;
    }
    if(checkEqual(count1,count2)){
        return true;
    }
    while(i<s2.length()){
        char newChar=s2[i];
        count2[newChar-'a']++;
        char oldChar=s2[i-windowSize];
        count2[oldChar-'a']--;
        i++;
        if(checkEqual(count1,count2)){
            return true;
        }
    }


}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<permutation(s1,s2);
    return 0;
}