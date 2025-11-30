//
#include <iostream>
using namespace std;

int main() {
    int arr[5]={3,4,2,8,6};
    int i,j,k=2;
    int count=0;
    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(arr[i]-arr[j]==k){
              count++;
            }
        }
    }
    cout<<"Number of ordered pairs:"<<count;
    return 0;
}