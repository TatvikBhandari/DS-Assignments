#include <iostream>
#include <string>
using namespace std;

int isSub(string a, string b) {
    return (b.find(a) != string::npos);
}

int main() {
    string s = "ababa";

    int n = s.size();
    int possible = 0;

    for (int i = 1; i < n && !possible; i++) {
        for (int j = i + 1; j < n && !possible; j++) {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            if ((isSub(A,B) && isSub(A,C)) ||
                (isSub(B,A) && isSub(B,C)) ||
                (isSub(C,A) && isSub(C,B))) {
                possible = 1;
                cout << "YES\n";
                cout << "Split: " << A << " | " << B << " | " << C << endl;
            }
        }
    }

    if (!possible) cout << "NO\n";
    return 0;
}
