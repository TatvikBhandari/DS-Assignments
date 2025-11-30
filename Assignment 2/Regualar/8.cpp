//to count the total number of distinct elements in an array of length n
#include <iostream>
using namespace std;

int main() {
    int n=8;
    int arr[n]={1,1,2,3,3,3,4,4};
    int distinct=0,i,j;
    for(i=0;i<n;i++){
       for (j=0;j<i;j++) {   
            if (arr[i]==arr[j])
                break;
        }
        if (j==i) 
            distinct++;
    }
    cout<<"Total distinct elements:"<<distinct;
    return 0;
}
