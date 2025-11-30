#include<bits/stdc++.h>
using namespace std;

int main() {
  stack<char> rev;
  string s = "DataStructures";
  for(int i=0; i<s.length(); i++){
    rev.push(s[i]);
  }
  for(int i=0; i<s.length(); i++){
    cout<<rev.top();
    rev.pop();
  }

  return 0;
}