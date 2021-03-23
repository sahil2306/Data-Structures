#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return 0;
    }
    
}

string convert(string in){
    string pre;
    stack<char> st;

    for(int i=0;i<in.size();i++){

        if(in[i]>='a' && in[i]<='z'){
            //add as it is
            pre+=in[i];
        }
        else if(in[i]=='('){
            st.push(in[i]);
        }
        else if(in[i]==')'){
            //remove all till ()
            while(!st.empty() && st.top()!='('){
                pre+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(in[i])){
                pre+=st.top();
                st.pop();
            }
            st.push(in[i]);
        }
    }

    while(!st.empty()){
        pre+=st.top();
        st.pop();
    }

    reverse(pre.begin(), pre.end());

    return pre;

}

string rev(string s){
    reverse(s.begin(), s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            s[i] = '(';
        }
        else if(s[i]=='('){
            s[i] = ')';
        }
    }
    return s;
}

int main(){
    string in = "(a-b/c)*(a/k-l)";
    in = rev(in);
    cout<<"\n"<<convert(in);
    
    return 0;
}