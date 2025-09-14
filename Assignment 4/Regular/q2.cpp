//Circular Queues:enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#include <iostream>
using namespace std;
class queue{
    int *arr;
    int front,rear,size;
    public:
    queue(int s){
        size=s;
        front=-1;
        rear=-1;
        arr=new int[size];
    }
    int isFull(){ 
       if((front==0 && rear==size-1)||(front==rear+1)){
        return 1;
       }
       return 0;
    }
    int isEmpty(){
        if(front==-1){
            return 1;
        }
        return 0;
    }
    void frontenqueue(int item){
        if((front==0 && rear==size-1)|| front==rear+1){
            cout<<"Deque is full";
            return;
        }
        if(front==-1){
           front=rear=0;            
        }
        else if(front==0){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=item;
    }
    void rearenqueue(int item){
        if((front==0 && rear==size-1)||front==rear+1){
            cout<<"Deque is full";
            return;
        }
        if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=item;
    }
    void frontdequeue(){
        if(isEmpty()){
            cout<<"Deque is empty";
            return;
        }
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }
    void reardequeue(){
        if(isEmpty()){
            cout<<"Deque is empty";
            return;
        }
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
    }
    void display(){
        for(int i=front;i!=rear;i=(i+1)%size){
        cout<<arr[i]<<" ";
    }
    cout<<arr[rear];
    cout<<endl;
    }
};
int main() {
    queue q(5);
    q.frontenqueue(10);
    q.frontenqueue(20);
    q.frontenqueue(30);
    q.display();
    return 0;
}
