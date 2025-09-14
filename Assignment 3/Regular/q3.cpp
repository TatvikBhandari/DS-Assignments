//to check expression has balanced parrenthesis or not
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int isBalanced(string str){
    stack<char> s;
    int n=str.length();
    for(int i=0;i<n;i++){
        char c=str[i];
        if(c=='('){
            s.push(c);
        }
        else if(c==')'){
             if (s.empty()) {
                return 0; 
            }
            if (s.top()!='(') {
                return 0; 
            }
            s.pop();
        }
    }
    return s.empty() ?1:0;
}
int main() {
    string str;
    cout<<"Enter an expression: ";
    cin>>str;

    if(isBalanced(str)==1)
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;
    return 0;
}