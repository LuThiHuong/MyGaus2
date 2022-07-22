//
// Created by Lu Thi Huong on 22/07/2022.
//
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
void khuGaussJordan(int n){
    bienAThanhMatranBoSung();
    float t;
    for (int i = 1; i <= n; ++i) {
        if (A[i][i] == 0){
            printf("Err");
            exit(0);
        }
        for (int j = 1; j <= n ; ++j) {
            if (i != j){
                t = A[j][i] / A[i][i];
                for (int k = 1; k <= n+1; ++k) {
                    A[j][k] = A[j][k] - t * A[i][k];
                }
            }
        }
    }
}