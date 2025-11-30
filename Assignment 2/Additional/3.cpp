#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int n1 = str1.size(), n2 = str2.size();

    if (n1 != n2) {
        cout << "Not Anagram";
        return 0;
    }

    int freq[26] = {0};

    for (int i = 0; i < n1; i++)
        freq[str1[i] - 'a']++;

    for (int i = 0; i < n2; i++)
        freq[str2[i] - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            cout << "Not Anagram";
            return 0;
        }
    }

    cout << "Anagram";
    return 0;
}
