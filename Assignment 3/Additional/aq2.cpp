//a stack that supports getMin() in O(1) time and O(1) extra space
#include <iostream>
using namespace std;

class stack{
    int top=-1;
    int *arr;
    int size;
    public:
    stack(int s){
       size=s;
       arr=new int[size];
    }
    void push(int);
    void pop();
    void show();
    void getMin();
};

void stack::push(int item){
    if(top==size-1){
        cout<<"Stack is overflow";
    }
    else
    top++;
    arr[top]=item;
}
void stack::pop(){
    if(top==-1){
        cout<<"Stack is underflow";
    }
    else
    top--;
}
void stack::show(){
    int i;
    for(i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}
//its O(n) 
void stack::getMin(){
    int min=arr[top];
    for(int i=top;i>0;i--){
        if(min>arr[i-1]){
            min=arr[i-1];
        }
    }
    cout<<min;
}
int main() {
    stack s(5);
    s.push(3);
    s.push(2);
    s.push(4);
    s.getMin();
    return 0;
}