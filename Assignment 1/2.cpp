//deleting duplicates from the array
#include <iostream>
using namespace std;

int main() {
    int n=5;
    int arr[n]={2,1,1,3,2};
    int n1=n;
    for(int i=0;i<n1;i++){
        for(int j=i+1;j<n1;j++){
            if(arr[i]==arr[j]){
                
                for(int k=j;k<n1-1;k++){
                    arr[k]=arr[k+1];
                }
                n1--;
                j--;
            }
        }
    }
    for(int i=0;i<n1;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}