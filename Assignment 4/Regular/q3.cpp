//Write a program interleave the first half of the queue with second half
#include <iostream>
#include <queue>
using namespace std;

void Queue(queue<int>& q){
    int n=q.size();

    queue<int>firsthalf;
    int half=n/2;

    for(int i=0;i<n/2;i++){
        firsthalf.push(q.front());
        q.pop();
    }

    while(!firsthalf.empty()){
        q.push(firsthalf.front());
        firsthalf.pop();

        q.push(q.front());
        q.pop();
    }
}
int main() {
    queue<int> q;

    q.push(1);q.push(2);q.push(3);q.push(4);q.push(5);q.push(6);
    
    Queue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}