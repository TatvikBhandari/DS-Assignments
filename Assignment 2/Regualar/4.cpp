//strings
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    //conctenate a string
    string str1="Hello";
    string str2="World";
    string str3=str1+str2;
    cout<<str3<<endl;

    //reverse a string
    int n=str1.length();
    for(int i=0;i<n/2;i++){
        swap(str1[i],str1[n-i-1]);
    }
    cout<<str1<<endl;

    //delete all vowels from string
    string result = ""; 
    for (int i=0;i<n;i++) {
        char ch=str1[i];
        if (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' &&
            ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U') {
            result+=ch;
        }
    }

    cout<<result<<endl;

    //sort the strings in alphabetical order
    string str4="HeLlO";
    sort(str4.begin(),str4.end());
    cout<<str4<<endl;

    //uppercase to lowercase
    for (int i=0;i<str4.length();i++) {
        str4[i]=tolower(str4[i]);   
    }

    cout<<str4<<endl;
    return 0;
}