#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){ 
        cin>>arr[i];
    }
    int possibleDups=0;
    int last=n-1;
    for (int i=0;i<=last-possibleDups;i++){
        if(arr[i]==2){
            if(i==last-possibleDups){
                arr[last]=2;
                last--;
                break;
            }
            possibleDups++;
        }
    }
    int j=last-possibleDups;
    for (int i=j;i>=0;i--) {
        if (arr[i]==2){
            arr[i+possibleDups]=2;
            possibleDups--;
            arr[i+possibleDups]=2;
        } else{
            arr[i+possibleDups]=arr[i];
        }
    }
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
