#include "mattrans.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    static int A[N][N];
    static int B[N][N];

    srand(time(0));

    // ÀH¾÷²£¥Í¯x°} (1~9)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 9 + 1;
        }
    }

    // ©I¥s top function
    mattrans(A, B);

#ifndef __SYNTHESIS__
    cout << "Matrix A:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix B (Transpose):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
#endif

    return 0;
}
