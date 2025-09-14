//menu driven program to push,pop,isEmpty,Isfull,display
#include <iostream>
using namespace std;

class Stack{
  int *arr;
  int top;
  int size;
  public:
  Stack(int s){
    size=s;
    arr=new int[size];
    top=-1;
  }
  void isFull(){
    if(top==size-1){
        cout<<"Stack is overflow";
    }
  }
  void isEmpty(){
    if(top==-1){
        cout<<"Stack is undeflow";
    }
  }
  void push(int item){
    if(top==size-1){
        cout<<"Stack is overflow";
    }
    else{
        top++;
        arr[top]=item;
    }
  }
  void pop(){
    if(top==-1){
        cout<<"Stack is undeflow";
    }
    else{
        top--;
    }
  }
  void show(){
    int i;
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    for(i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
  void display(){
    int choice,val;
    cout<<"Enter operations :"<<endl;
    cout<<"1-Push,2-Pop,3-isFull,4-isEmpty,5-show"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter value to push:";
        cin>>val;
        push(val);
        break;
        case 2:
        pop();
        break;
        case 3:
        isFull();
        break;
        case 4:
        isEmpty();
        break;
        case 5:
        show();
        break;
        default:
        cout<<"Invalid Choice"<<endl;
    }
  }
};
int main() {
    Stack s(5);
    s.display();
    s.display();
    return 0;
}