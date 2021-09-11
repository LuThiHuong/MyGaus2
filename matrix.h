//
// Created by TuanAnh on 8/17/2021.
//

#ifndef MYGAUSS_MATRIX_H
#define MYGAUSS_MATRIX_H

float A[10][10], X[10], B[10], Y[10]; // Khởi tạo ma trận hệ số, ma trận nghiệm, ma trận giá trị B ban đầu, Y ban đầu phục vụ Cholesky
int n; // Số ẩn của hệ phương trình

void toiGianHeSo(){
    float maxA;
    for (int i = 1; i <= n; ++i) {
        maxA = fabs(A[i][1]);
        for (int j = 1; j <= n; ++j) {
            if (fabs(A[i][j]) >= maxA){
                maxA = fabs(A[i][j]);
            }
        }
        for (int j = 1; j <= n; ++j) {
            A[i][j] = A[i][j] / maxA;
        }
        B[i] = B[i] / maxA;
    }
}

void inMaTranHeSo(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%lf \t", A[i][j]);
        }
        printf("\n");
    }
}

void inNghiem(){
    for (int i = 1; i <=n; ++i) {
        printf("X[%d] = %.20f \n",i,X[i]);
    }
}

void inMaTranBoSung(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            printf("%lf \t", A[i][j]);
        }
        printf("\n");
    }
}

void bienAThanhMatranBoSung(){
    for (int i = 1; i <= n; i++) {
        A[i][n+1] = B[i];
    }
}
#endif //MYGAUSS_MATRIX_H
