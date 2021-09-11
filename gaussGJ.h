//
// Created by TuanAnh on 8/17/2021.
//

#ifndef MYGAUSS_GAUSSGJ_H
#define MYGAUSS_GAUSSGJ_H
// Hàm biến đổi ma trận bổ sung ban đầu về ma trận bậc thang sử dụng thuật toán khử Gauss
void khuGauss(int n) {
    bienAThanhMatranBoSung();
    float t;
    for (int i = 1; i <= n; i++) {
        if (A[i][i] == 0) {
            printf("Err");
            exit(0);
        }
        for (int k = i + 1; k <= n; k++) {
            t = A[k][i] / A[i][i];
            for (int j = 1; j <= n + 1; j++) {
                A[k][j] = A[k][j] - t * A[i][j];
            }
        }
    }
}

// Hàm biến đổi ma trận bổ sung dùng thuật toán Gauss-Jordan
void gaussJordan(int n){
    bienAThanhMatranBoSung();
    float t;
    for (int i = 1; i <= n; ++i) {
        if (A[i][i] == 0){
            printf("Err");
            exit(0);
        }
        for (int j = 1; j <= n ; ++j) {
            if (j != i){
                t = A[j][i] / A[i][i];
                for (int k = 1; k <= n+1; ++k) {
                    A[j][k] = A[j][k] - t * A[i][k];
                }
            }
        }
    }
}

// Hàm giải hệ phương trình sau khi đã đưa ma trận bổ sung về ma trận bậc thang
void giaiHeGauss(int n) {
    X[n] = A[n][n+1]/A[n][n];
    for (int i = n - 1; i >= 1; i--) {
        X[i] = A[i][n+1];
        for (int j = i + 1; j <= n; j++) {
            X[i] = X[i] - A[i][j] * X[j];
        }
        X[i] = X[i] / A[i][i];
    }
}

#endif //MYGAUSS_GAUSSGJ_H
