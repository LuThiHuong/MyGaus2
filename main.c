/*
 * CHÚ Ý: Để dễ thao tác thì các mảng ma trận trong code này sẽ chạy từ phần tử 1
 * Do vị trí của ma trận thường bắt đầu từ phần tử [1][1]
 * Dinh Tuan Anh 20185429
 */

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include <stdbool.h>
// ================================ KHÔNG XÓA CÁC IMPORT TRÊN DÒNG NÀY=====================================
#include "matrix.h"
#include "cholesky.h"
#include "gaussGJ.h"
#include "singleLoop.h"

void main() {
    n = 3;
    A[1][1] = 1;
    A[1][2] = 0.4;
    A[1][3] = -0.3;
    A[2][1] = 0.3;
    A[2][2] = 1.1;
    A[2][3] = -0.3;
    A[3][1] = 0.2;
    A[3][2] = -0.1;
    A[3][3] = 1.3;
    B[1] = 0.5;
    B[2] = 0.4;
    B[3] = 0.12;


    inMaTranHeSo();
    printf("-=====================================================- \n");
    chooseMatrix(2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%lf \t", AC[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <=3 ; ++i) {
        printf("norm = %f\n", getNormMatrix(i));
    }
    singleLoop();
    inNghiem();
}