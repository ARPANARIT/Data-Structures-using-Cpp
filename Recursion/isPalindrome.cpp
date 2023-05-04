#include<iostream>
using namespace std;
//check palindrome 
//strategy: 
//         1.get a starting pointer pointing to first index
//         2.base case: if start index crosses half the length of string then return true
//         3. check if first and last index same or not
//             if not same return false
//             else call recursively for next index
bool isPalindrome(int i, string s){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return isPalindrome(i+1,s);
}
int main(){
    string s ="uwu";
    if(isPalindrome(0,s)) cout<<s<<" : is Palindrome";
    else cout<<"not a Palindrome";
    return 0;
}