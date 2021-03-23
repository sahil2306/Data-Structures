#include<iostream>
#include<stack>
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
    string post;
    stack<char> st;

    for(int i=0;i<in.size();i++){

        if(in[i]>='a' && in[i]<='z'){
            //add as it is
            post+=in[i];
        }
        else if(in[i]=='('){
            st.push(in[i]);
        }
        else if(in[i]==')'){
            //remove all till ()
            while(!st.empty() && st.top()!='('){
                post+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(in[i])){
                post+=st.top();
                st.pop();
            }
            st.push(in[i]);
        }
    }

    while(!st.empty()){
        post+=st.top();
        st.pop();
    }

    return post;

}

int main(){
    string in = "(a-b/c)*(a/k-l)";
    
    cout<<"\n"<<convert(in);
    
    return 0;
}