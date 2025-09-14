#include <iostream>
using namespace std;

class stack{
    int *arr;
    int *arr1;
    int size,top;
    int k=0;
    public:
    stack(int s){
        size=s;
        top=-1;
        arr=new int[size];
        arr1=new int[size];
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
            cout<<"Stack is underflow";
        }
        else{
            top--;
        }
    }
    void smallest() {
        for (int i=0;i<size;i++) {
            int nearest=-1;
            for (int j=i-1;j>=0;j--){
                if (arr[j]<arr[i]){
                    nearest=arr[j];
                    break;
                }
            }
            arr1[k++]=nearest;
        }
    }
    void display(){
        for(int i=0;i<k;i++){
           cout<<arr1[i]<<" ";
        }
    }
};
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    stack s(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        s.push(x);
    }
    s.smallest();
    s.display();
    return 0;
}