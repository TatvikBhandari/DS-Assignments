//reverse of string using stack
#include <iostream>
#include <string.h>
using namespace std;

class reverse{
    int top;
    int size;
    char *str;
    char *stack;
    public:
    reverse(int s){
      size=s;
      top=-1;
      str=new char[size];
      stack=new char[size];  
    }
    void push(char item){
       if(top==size-1){
        cout<<"Stack is overflow";
       }
       else{
        top++;
        str[top]=item;
       }
    }
    void display(){
        int i,j=0;
        for(i=top;i>=0;i--,j++){
            stack[j]=str[i];
        }
        stack[j]='\0';
        cout<<"Reversed String :"<<stack;
    }
};
int main() {
    char n[20];
    cout<<"Enter any string :";
    cin>>n;
    int s=strlen(n);
    reverse st(s);
    for(int i=0;n[i]!='\0';i++){  
        st.push(n[i]);
    }
    st.display();
    return 0;
}