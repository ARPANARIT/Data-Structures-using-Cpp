#include<iostream>
#include<stack>
using namespace std;

stack<int> st;

void insertAtBottom(stack<int> &st,int ele){
// we here get the rest of the reversed stack and only push the last element to the bottom with the help of call stack frame
// here we can store the elements using the call stack
    if(st.empty()){
        st.push(ele);
        return;
    }
    
    int topele=st.top();// storing element popping and dumping it to call stack
    st.pop();
    insertAtBottom(st,ele);//insert at bottom the element which called the recursion to return the rest of reversed stack
    st.push(topele);//push the reversed stack back
}


void reverseStack(stack<int> &st){
// we are not using other stack to store 
    if(st.empty()){ 
        return;
    }
    int ele=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,ele);
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    reverseStack(st);
    while(!st.empty()){
    cout<<st.top()<<"|";
    st.pop();
    }cout<<endl;
    
    return 0;

}