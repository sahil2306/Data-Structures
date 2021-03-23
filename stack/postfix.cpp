#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int eval(string post){
    stack<int> st;
    
    for(int i=0;i<post.size();i++){
        
        if(post[i]>='0' && post[i]<='9'){
            st.push(post[i]-'0');
        }
        else{

            int two = st.top();
            st.pop();
            int one = st.top();
            st.pop();

            switch(post[i]){
                
                case '+':{
                    st.push(one+two);
                    break;
                }
                case '-':{
                    st.push(one-two);
                    break;
                }
                case '*':{
                    st.push(one*two);
                    break;
                }
                case '/':{
                    st.push(one/two);
                    break;
                }
                case '^':{
                    st.push(pow(one,two));
                    break;
                }
            }

            
        }

    }
    return st.top();

}

int main(){

    string postfixEQ = "46+2/5*7+";
    int ans = eval(postfixEQ);

    cout<<"postfix Evaluation : "<<ans;

    return 0;
}