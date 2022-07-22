

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
    fin = fopen("C:\\Users\\Lu Thi Huong\\CLionProjects\\GTSC2\\input.txt","r");
    fscanf(fin,"%d\n",&n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fscanf(fin,"%f\n",&A[i][j]) ;
        }
    }
    for (int i = 1; i <= n; ++i) {
        fscanf(fin,"%f\n",&B[i]);
    }

    inMaTranHeSo();
    printf("-=====================================================- \n");
    khuGaussJordan(n);
//    CholeskyDes(n);
// jacobi(checkCheoTroi(n));
    inMaTranBoSung();
    giaiHeGauss(n);
//    giaiHeCholesky(n);
    inNghiem();
    fclose(fin);
}