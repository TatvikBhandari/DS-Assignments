#include <iostream>
using namespace std;

class Sparse {
    int rows, cols, terms;
    int data[100][3];   
public:
    void input() {
        cout << "Enter rows, cols and number of non-zero terms: ";
        cin >> rows >> cols >> terms;
        cout << "Enter row, col, val for each non-zero term:\n";
        for (int i = 0; i < terms; i++) {
            cin >> data[i][0] >> data[i][1] >> data[i][2];
        }
    }
    void display() {
        cout << "\nRow\tCol\tValue\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i][0] << "\t" << data[i][1] << "\t" << data[i][2] << endl;
        }
    }
    //Transpose
    Sparse transpose() {
        Sparse t;
        t.rows = cols;
        t.cols = rows;
        t.terms = terms;
        int k = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < terms; j++) {
                if (data[j][1] == i) {
                    t.data[k][0] = data[j][1];
                    t.data[k][1] = data[j][0];
                    t.data[k][2] = data[j][2];
                    k++;
                }
            }
        }
        return t;
    }
    //Addition
    Sparse add(Sparse b) {
        Sparse c;
        if (rows != b.rows || cols != b.cols) {
            cout << "Addition not possible!\n";
            c.terms = 0;
            return c;
        }
        c.rows = rows;
        c.cols = cols;
        int i = 0, j = 0, k = 0;
        while (i < terms && j < b.terms) {
            if (data[i][0] == b.data[j][0] && data[i][1] == b.data[j][1]) {
                int sum = data[i][2] + b.data[j][2];
                if (sum != 0) {
                    c.data[k][0] = data[i][0];
                    c.data[k][1] = data[i][1];
                    c.data[k][2] = sum;
                    k++;
                }
                i++; j++;
            }
            else if ((data[i][0] < b.data[j][0]) ||
                     (data[i][0] == b.data[j][0] && data[i][1] < b.data[j][1])) {
                c.data[k][0] = data[i][0];
                c.data[k][1] = data[i][1];
                c.data[k][2] = data[i][2];
                k++; i++;
            }
            else {
                c.data[k][0] = b.data[j][0];
                c.data[k][1] = b.data[j][1];
                c.data[k][2] = b.data[j][2];
                k++; j++;
            }
        }
        while (i < terms) {
            c.data[k][0] = data[i][0];
            c.data[k][1] = data[i][1];
            c.data[k][2] = data[i][2];
            k++; i++;
        }
        while (j < b.terms) {
            c.data[k][0] = b.data[j][0];
            c.data[k][1] = b.data[j][1];
            c.data[k][2] = b.data[j][2];
            k++; j++;
        }
        c.terms = k;
        return c;
    }
    //Multiplication
    Sparse multiply(Sparse b) {
        Sparse c;
        if (cols != b.rows) {
            cout << "Multiplication not possible!\n";
            c.terms = 0;
            return c;
        }
        c.rows = rows;
        c.cols = b.cols;
        c.terms = 0;
        Sparse bt = b.transpose();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                int sum = 0;
                for (int p = 0; p < terms; p++) {
                    if (data[p][0] == i) {
                        for (int q = 0; q < bt.terms; q++) {
                            if (bt.data[q][0] == j && bt.data[q][1] == data[p][1]) {
                                sum += data[p][2] * bt.data[q][2];
                            }
                        }
                    }
                }
                if (sum != 0) {
                    c.data[c.terms][0] = i;
                    c.data[c.terms][1] = j;
                    c.data[c.terms][2] = sum;
                    c.terms++;
                }
            }
        }
        return c;
    }
};

int main() {
    Sparse A, B;
    cout << "Enter first sparse matrix:\n";
    A.input();
    cout << "Enter second sparse matrix:\n";
    B.input();
    cout << "\nFirst Matrix (Triplet form):";
    A.display();
    cout << "\nSecond Matrix (Triplet form):";
    B.display();
    cout << "\nTranspose of First Matrix:";
    Sparse T = A.transpose();
    T.display();
    cout << "\nAddition of A and B:";
    Sparse S = A.add(B);
    S.display();
    cout << "\nMultiplication of A and B:";
    Sparse M = A.multiply(B);
    M.display();
    return 0;
}
