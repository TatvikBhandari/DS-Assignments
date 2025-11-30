// question 1
#include<iostream>
using namespace std;

int main(){
    int t;
    cout<<"choose any one:"<<endl;
    cout<<"enter 1 to create"<<endl;
    cout<<"enter 2 to display"<<endl;
    cout<<"enter 3 to insert"<<endl;
    cout<<"enter 4 to delete"<<endl;
    cout<<"enter 5 to linear search"<<endl;
    cout<<"enter 6 to exit"<<endl;
    cin>>t;
    int arr[5]={1,2,3,4};
    //create
    if(t==1){
        cout<<"array has been created";
    }
    //display
    else if(t==2){
        int i;
        for(i=0;i<4;i++){
            cout<<arr[i]<<" ";
        }
    }
    //insert
    else if(t==3){
        int n,num,i;
        cout<<"enter index at which element be inserted:";
        cin>>n;
        cout<<"enter number:";
        cin>>num;
        
        for(i=4;i>n;i--){
            arr[i]=arr[i-1];
        }
        arr[n]=num;
        
        for(i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }
    }
    //delete
    else if(t==4){
        int n,i;
        cout<<"enter index which you want to delete:";
        cin>>n;
        for(i=n;i<4;i++){
            arr[i]=arr[i+1];
        }
        int n1=4;
        n1=n1-1;
        for(i=0;i<n1;i++){
            cout<<arr[i]<<" ";
        }
    }
    //linear search
    else if(t==5){
        int num,i;
        cout<<"enter number you want to find:";
        cin>>num;
        int val=0;
        
        for(i=0;i<4;i++){
            if(arr[i]==num){
                val=1;
                break;
            }
            else{
                val=0;
            }
        }   
        if(val==0){
            cout<<"element not found"<<endl;
        }
        else{
            cout<<"element found at index "<<i<<endl;
        }
    }
    else
    cout<<"Exited...";
    return 0;
}