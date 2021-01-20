#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string str = "AbcDef";

    //To Upper Case : 
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }
    cout<<"\nUpper Case is : "<<str;

    //To Lower Case : 
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
    }
    cout<<"\nLower Case is : "<<str<<endl;

    //Number string sorting : 
    string s = "12345986";
    for(int i=0;i<s.size();i++){
        sort(s.begin(),s.end(),greater<int>()); //greater<datatype> for reverse sorting
    }
    cout<<s;

    //
}