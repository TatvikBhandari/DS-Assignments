#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int temperatures[n];
    for (int i=0;i<n;i++){
        cin>>temperatures[i];
    }

    int answer[n];        
    for (int i=0;i<n;i++){
        answer[i] = 0;
    }
    int st[n];                   
    int top=-1;                

    for (int i=n-1;i>=0;i--){
        while(top>=0 && temperatures[st[top]]<=temperatures[i]){
            top--;
        }
        if (top>=0) {
            answer[i]=st[top]-i; 
        }
        st[++top]=i; 
    }
    for (int i=0;i<n;i++){
        cout<<answer[i]<< " ";
    }
    return 0;
}
