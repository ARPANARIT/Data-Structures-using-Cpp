#include<iostream>
#include<stack>
using namespace std;


int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/'||c=='*'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixtoprefix(string s){
    string prefix;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])){
            prefix+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&& st.top()!='('){
                prefix+=st.top();
                st.pop();
            }
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
        }
        else{
            if(!st.empty()&&precedence(s[i])<=precedence(st.top())){
                prefix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.empty()){
        prefix+=st.top();
        st.pop();
    }
    return prefix;
}





int main(){
    cout<<infixtoprefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}