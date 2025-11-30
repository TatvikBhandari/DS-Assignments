//Matrix
#include <iostream>
using namespace std;

int main() {
    int i,j;
    //Diagonal Matrix
    int arr1[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==j){
                arr1[i][j]=1;
                cout<<arr1[i][j]<<" ";
            }
            else{
                arr1[i][j]=0;
                cout<<arr1[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    //Tridiagonal Matrix
    int arr2[3][3];int p;
    for(i=0;i<3;i++){
        for(j=0,p=1;j<3;j++,p++){
            if(i==j){
                arr2[i][j]=p;
                cout<<arr2[i][j]<<" ";
            }
            else{
                arr1[i][j]=0;
                cout<<arr1[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;

    //Lower Triangular Matrix
    int arr3[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i>=j){
                arr3[i][j]=1;
                cout<<arr3[i][j]<<" ";
            }
            else{
                arr3[i][j]=0;
                cout<<arr3[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    
    //Upper Triangular Matrix
    int arr4[i][j];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i<=j){
                arr4[i][j]=1;
                cout<<arr4[i][j]<<" ";
            }
            else{
                arr4[i][j]=0;
                cout<<arr4[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}