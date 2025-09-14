//Convert an Infix expression into a Postfix expression
#include <iostream>
#include <stack>
#include <string.h>
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
        return -1;
    }
}
string infixtopostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))||((c>='0')&&(c<='9'))){
            res+=c;
        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(c)<=prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(c);
        }

    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixtopostfix(exp);
    return 0;
}