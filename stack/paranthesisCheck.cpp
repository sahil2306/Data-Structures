#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    
    stack<int> st;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty()){
                if(st.top()!='('){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                return false;
            }
        }
        else if(s[i]==']'){
            if(!st.empty()){
                if(st.top()!='['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                return false;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty()){
                if(st.top()!='{'){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                return false;
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return true;
}

int main(){
    string s;
    cout<<"\nEnter an equation : ";
    cin>>s;

    cout<<"\nIs the equation well paranthesised? ";
    cout<<check(s);
}