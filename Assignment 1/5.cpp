//sum of each row and each coloumn
#include <iostream>
using namespace std;

int main() {
    int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int i,j,rs,cs;

    for(i=0;i<3;i++){
        rs=0;cs=0;
        for(j=0;j<3;j++){
            rs+=arr1[i][j];
            cs+=arr1[j][i];
        }
        cout<<"sum of row "<<i+1<<" :"<<rs<<endl;
        cout<<"sum of coloumn "<<i+1<<" :"<<cs<<endl;
    }
    return 0;
}