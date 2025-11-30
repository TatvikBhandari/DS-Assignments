#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;
    PriorityQueue() {
        size = 0;
    }
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    void heapifyDown(int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        if (i > 0 && arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapifyUp(parent);
        }
    }
    void push(int x) {
        arr[size] = x;
        heapifyUp(size);
        size++;
    }
    int top() {
        if (size == 0) return -1;
        return arr[0];
    }
    void pop() {
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }
    bool empty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    return 0;
}
