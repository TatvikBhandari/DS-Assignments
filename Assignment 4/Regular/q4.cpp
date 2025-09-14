#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    queue<char> q;          
    int freq[256] = {0};    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];       
        freq[(int)c]++;      
        q.push(c);           
        while (!q.empty() && freq[(int)q.front()] > 1) {
            q.pop();
        }
    }

    if (!q.empty())
        cout << "First non-repeating character: " << q.front() << endl;
    else
        cout << "No non-repeating character found." << endl;

    return 0;
}
