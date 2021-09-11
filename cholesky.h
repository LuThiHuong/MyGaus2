//
// Created by TuanAnh on 8/17/2021.
//

#ifndef MYGAUSS_CHOLESKY_H
#define MYGAUSS_CHOLESKY_H

// Hàm kiểm tra tính đối xứng của ma trận
bool checkSymetric(int n){
    bool check = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] != A[j][i]){
                check = false;
            }
        }
    }
    return check;
}

// Hàm xử lý ma trận đối xứng theo Cholesky Descomposition
void CholeskyDes(int n){
    bool check = checkSymetric(n);
    if (check == false){
        printf("Ma tran khong doi xung, khong the thuc hien thuat toan \n");
        exit(0);
    } else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <=n ; ++j) {
                if (i == 1){
                    if (j == 1){
                        A[i][j] = sqrt(A[i][j]);
                    }
                    if (j > 1){
                        A[i][j] = A[i][j]/A[1][1];
                    }
                }
                if (j == i){
                    if (j == 1){
                        continue;
                    } else {
                        for (int k = 1; k <= i - 1; ++k) {
                            A[i][j] = A[i][j] - pow(A[k][i],2);
                        }
                        if (A[i][j] <= 0){
                            printf("Ma tran da cho khong xac dinh duong \n");
                            exit(0);
                        }
                        if (A[i][j] > 0){
                            A[i][j] = sqrt(A[i][j]);
                        }
                    }
                }
                if (j > i){
                    for (int k = 1; k <= i - 1; ++k) {
                        A[i][j] = A[i][j] - A[k][i] * A[k][j];
                    }
                    A[i][j] = A[i][j] / A[i][i];
                }
                if (j < i){
                    A[i][j] = 0;
                }
            }
        }
    }
}

// Hàm Tìm nghiệm sau Cholesky Descomposition
void giaiHeCholesky(int n){
    float AT[10][10];
    int m = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            AT[i][j] = A[j][i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        AT[i][n+1] = B[m];
        m++;
    }
    printf("Ma tran U^T \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%lf \t", AT[i][j]);
        }
        printf("\n");
    }
    Y[1] = B[1] / AT[1][1];
    for (int i = 2; i <= n; ++i) {
        Y[i] = AT[i][n+1];
        for (int j = i - 1; j >= 1; --j) {
            Y[i] = Y[i] - AT[i][j] * Y[j];
        }
    }
    m = 1;
    for (int i = 1; i <= n; ++i) {
        A[i][n+1] = Y[m];
        m++;
    }
}

#endif //MYGAUSS_CHOLESKY_H
