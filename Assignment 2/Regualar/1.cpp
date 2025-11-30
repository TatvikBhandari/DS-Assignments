//to apply binary search
#include <iostream>

using namespace std;
int main() {
    int arr[5] = {1,2,3,4,5};
    int num = 4;
    int i,mid,left=0,right=4;
    mid=(left+right)/2;

    for(i=mid;i<5,left<=right;i++) {
        mid=(left+right)/2;
        if(num==mid) {
            cout<<"Number found at index :"<<mid-1<<endl;
            break;
        }
        else if(arr[i]>mid) {
            left=mid+1;
        }
        else if(arr[i]<mid) {
            right=mid-1;
        }
    }

    return 0;
}