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
#include "jacobi.h"

void main() {
    FILE *fin;
    fin = fopen("C:\\Users\\TuanAnh\\CLionProjects\\MyGauss\\input.txt","r");
    fscanf(fin,"%d\n",&n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fscanf(fin,"%f\n",&A[i][j]) ;
        }
    }
    inMaTranHeSo();
    printf("-=====================================================- \n");
    khuGauss(n);
    inMaTranHeSo();
    fclose(fin);
}