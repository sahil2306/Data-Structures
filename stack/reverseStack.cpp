#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int k){

    if(st.empty()){
        st.push(k);
        return;
    }
    int ele = st.top();
    st.pop();
    insertAtBottom(st,k);

    st.push(ele);
}

void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverse(st);
    
    insertAtBottom(st, ele);
}

void display(stack<int> &st){
    cout<<"\n";
    stack<int> s = st;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(8);
    st.push(10);
    cout<<"Before : ";
    display(st);

    reverse(st);
    
    cout<<"\nAfter : ";
    display(st);
    
}

