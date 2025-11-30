#include<iostream>
using namespace std;
#define MAXLEN 100

typedef struct{
  int element[MAXLEN];
  int top;
}stack;
stack init() {
  stack s;
  s.top = -1;
  return s;
}
int isEmpty(stack s){
  return (s.top==-1);
}
int isFull(stack s){
  return (s.top==MAXLEN-1);
}
int peek(stack s){
  if(isEmpty(s)){
    cout<<"Empty stack\n";
  } else {
    return s.element[s.top];
  }
}
stack push(stack s, int x){
  if(isFull(s)){
    cout<<"Overflow\n";
  } else {
    ++s.top;
    s.element[s.top] = x;
  }
  return s;
}
stack pop(stack s){
  if(isEmpty(s)){
    cout<<"Underflow\n";
  } else {
    --s.top;
    return s;
  }
}
void display(stack s){
  int i;
  for(i=s.top; i>=0; --i){
    cout<<s.element[i]<<" ";
  }
}

int main() {
  stack s;
  s = init();
  s = push(s,10);
  s = push(s,45);
  s = push(s,1);
  s = push(s,50);
  cout<<"Current stack: \n";
  display(s);
  cout<<" with top: "<<peek(s)<<endl;
  s = pop(s);
  s = pop(s);
  cout<<"Current stack: ";
  display(s);
  cout<<" with top = "<<peek(s)<<endl;

  return 0;
}