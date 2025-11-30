#include <iostream>
using namespace std;

class Triplet {
public:
    int r, c, v;
};

class Sparse {
public:
    int rows, cols, nz;
    Triplet t[50];

    void set(int r, int c, int n) {
        rows = r;
        cols = c;
        nz = n;
        t[0] = {r, c, n};
    }

    void print() {
        for (int i = 0; i <= nz; i++)
            cout << t[i].r << " " << t[i].c << " " << t[i].v << endl;
    }
};

Sparse transpose(Sparse A) {
    Sparse T;
    T.set(A.cols, A.rows, A.nz);

    int k = 1;
    for (int col = 0; col < A.cols; col++)
        for (int i = 1; i <= A.nz; i++)
            if (A.t[i].c == col)
                T.t[k++] = {A.t[i].c, A.t[i].r, A.t[i].v};

    return T;
}

Sparse add(Sparse A, Sparse B) {
    Sparse C;
    if (A.rows != B.rows || A.cols != B.cols) {
        C.set(A.rows, A.cols, 0);
        return C;
    }

    int i = 1, j = 1, k = 1;
    C.set(A.rows, A.cols, 0);

    while (i <= A.nz && j <= B.nz) {
        if (A.t[i].r < B.t[j].r ||
           (A.t[i].r == B.t[j].r && A.t[i].c < B.t[j].c))
            C.t[k++] = A.t[i++];
        else if (B.t[j].r < A.t[i].r ||
                (B.t[j].r == A.t[i].r && B.t[j].c < A.t[i].c))
            C.t[k++] = B.t[j++];
        else {
            C.t[k] = {A.t[i].r, A.t[i].c, A.t[i].v + B.t[j].v};
            i++; j++; k++;
        }
    }

    while (i <= A.nz) C.t[k++] = A.t[i++];
    while (j <= B.nz) C.t[k++] = B.t[j++];

    C.nz = k - 1;
    C.t[0].v = C.nz;
    return C;
}

Sparse multiply(Sparse A, Sparse B) {
    Sparse C;
    if (A.cols != B.rows) {
        C.set(A.rows, B.cols, 0);
        return C;
    }

    C.set(A.rows, B.cols, 0);
    int k = 1;

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            int sum = 0;

            for (int x = 1; x <= A.nz; x++)
                if (A.t[x].r == i)
                    for (int y = 1; y <= B.nz; y++)
                        if (B.t[y].r == A.t[x].c && B.t[y].c == j)
                            sum += A.t[x].v * B.t[y].v;

            if (sum != 0)
                C.t[k++] = {i, j, sum};
        }
    }

    C.nz = k - 1;
    C.t[0].v = C.nz;
    return C;
}

int main() {
    Sparse A, B;

    A.set(3, 3, 3);
    A.t[1] = {0, 0, 5};
    A.t[2] = {0, 2, 8};
    A.t[3] = {2, 1, 6};

    B.set(3, 3, 2);
    B.t[1] = {0, 1, 3};
    B.t[2] = {2, 1, 4};

    cout << "Transpose:\n";
    transpose(A).print();

    cout << "Addition:\n";
    add(A, B).print();

    cout << "Multiplication:\n";
    multiply(A, B).print();

    return 0;
}
