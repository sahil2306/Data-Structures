#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int eval(string pre){
    stack<int> st;
    
    for(int i=pre.size()-1;i>=0;i--){
        if(pre[i]>='0' && pre[i]<='9'){
            st.push(pre[i]-'0');
        }
        else{

            int one = st.top();
            st.pop();
            int two = st.top();
            st.pop();

            switch(pre[i]){
                
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

    string prefixEQ = "-+7*45+02";
    int ans = eval(prefixEQ);

    cout<<"Prefix Evaluation : "<<ans;

    return 0;
}