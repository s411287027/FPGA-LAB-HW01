#include "mattrans.h"
#include <cmath>
#include <cstdio>

// 矩陣乘向量
void mat_vec_mul(double A[N][N], double x[N], double y[N]) {
    for (int i = 0; i < N; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++) {
            sum += A[i][j] * x[j];
        }
        y[i] = sum;
    }
}

// 向量正規化
double normalize(double x[N]) {
    double norm = 0.0;
    for (int i = 0; i < N; i++) {
        norm += x[i] * x[i];
    }
    norm = std::sqrt(norm);
    if (norm == 0) return 0.0;
    for (int i = 0; i < N; i++) {
        x[i] /= norm;
    }
    return norm;
}

// Power iteration
void eigen_power(double A[N][N], double eigen_vec[N], double *eigen_val) {
    static double b_k[N];
    static double b_next[N];

    for (int i = 0; i < N; i++) {
        b_k[i] = 1.0;  // 初始向量
    }

    for (int iter = 0; iter < ITER; iter++) {
        mat_vec_mul(A, b_k, b_next);
        normalize(b_next);

        for (int i = 0; i < N; i++) {
            b_k[i] = b_next[i];
        }
    }

    for (int i = 0; i < N; i++) {
        eigen_vec[i] = b_k[i];
    }

    static double temp[N];
    mat_vec_mul(A, b_k, temp);
    double num = 0.0, den = 0.0;
    for (int i = 0; i < N; i++) {
        num += b_k[i] * temp[i];
        den += b_k[i] * b_k[i];
    }
    *eigen_val = (den != 0.0) ? (num / den) : 0.0;
}

// top function
void mattrans(int A[N][N], int B[N][N]) {
    // 矩陣轉置
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[j][i] = A[i][j];
        }
    }

    // 轉成 double
    static double Bd[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Bd[i][j] = (double)B[i][j];
        }
    }

    // 計算特徵值與特徵向量
    static double eigvec[N];
    double eigval;
    eigen_power(Bd, eigvec, &eigval);

#ifndef __SYNTHESIS__
    printf("Eigenvalue = %f\n", eigval);
    printf("Eigenvector (前10項):\n[");
    for (int i = 0; i < 10; i++) {
        printf("%f ", eigvec[i]);
    }
    printf("...]\n");
#endif
}
