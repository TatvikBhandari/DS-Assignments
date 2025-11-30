//finding missing number
#include <iostream>
#include<array>
using namespace std;

int main() {
    int arr[]={1,2,3,4,5,6,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    //linearly
    int k=1;
    int last=9;
    for(int i=0;i<n;i++){
        while(arr[i]!=k){
            cout<<"The missing number :"<<k<<endl;
            k++;
        }
        k++;
    }
    //binary search
    int left=0,right=8;
    int mid;
    for(int i=0;i<n,left<=right;i++){
        mid=(left+right)/2;
        if(arr[mid]==mid+1){
            left=mid+1;
        }
        else
        right=mid-1;
    }
    cout<<"Missing element is:"<<left+1<<endl;
    return 0;
}