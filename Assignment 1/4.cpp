//reverse of array,matrix multiplication,transpose of matrix
#include <iostream>
using namespace std;

int main() {
    //reverse of array
    int n=5;
    int arr[n]={1,3,2,5,4};
    
    for(int i=0;i<n/2;i++){
        int temp= arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    //matrix multiplication
    int i,j,k;
    int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr2[3][3]={{9,8,7},{6,5,4},{3,2,1}};
    int arr3[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           arr3[i][j]=0;
           for(k=0;k<3;k++){
            arr3[i][j]+=arr1[i][k]*arr2[k][j];
           }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //transpose of matrix
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<arr1[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
