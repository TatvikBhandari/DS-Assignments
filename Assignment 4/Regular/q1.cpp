//enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#include <iostream>
using namespace std;
class queue{
  int *arr;
  int size,front,rear;
  public:
  void isEmpty(){
    if(front==rear){
        cout<<"queue is underflow";
    }
  }
  void isFull(){
    if(rear==size-1){
        cout<<"queue is overflow";
    }
  }
  queue(int s){
    size=s;
    front=-1;
    rear=-1;
    arr=new int[size];
  }
  void enqueue(int item){
    if(rear==size-1){
        cout<<"queue is overflow";
    }
    else{
        front=0;
        rear=rear+1;
        arr[rear]=item;
    }
  }
  void dequeue(){
    if(front==rear){
        cout<<"queue is underflow";
    }
    else{
        front+=1;
    }
  }
  void display(){
    for(int i=front;i<=rear;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
  void show(){
    int choice,value;
    cout<<"Enter operation:"<<endl;
    cout<<"1-enqueue,2-dequeue,3-display,4-exit";
    cout<<"Enter choice:";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter value:";
        cin>>value;
        enqueue(value);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        cout<<"Exiting...";
    }
  }
};
int main() {
    queue q(5);
    q.show();
    q.show();
    return 0;
}