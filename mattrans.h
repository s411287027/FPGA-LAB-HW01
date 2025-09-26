#ifndef MATTRANS_H
#define MATTRANS_H

#define N 512
#define ITER 50

// top function
void mattrans(int A[N][N], int B[N][N]);

// eigen¬ÛÃö
void mat_vec_mul(double A[N][N], double x[N], double y[N]);
double normalize(double x[N]);
void eigen_power(double A[N][N], double eigen_vec[N], double *eigen_val);

#endif
