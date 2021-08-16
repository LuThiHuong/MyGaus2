//
// Created by TuanAnh on 8/17/2021.
//

#ifndef MYGAUSS_SINGLELOOP_H
#define MYGAUSS_SINGLELOOP_H

const float esl = 1e-6;
float A1[10][10],A2[10][10],AC[10][10],BS[10],XI[10];

// Hàm khởi tạo, tạo ra hai ma trận alpha theo 2 cách xác định alpha khác nhau
void createSL(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j != i){
                A1[i][j] = A[i][j];
                A2[i][j] = A[i][j];
            }
            if (j == i){
                A1[i][j] = A[i][j] + 1;
                A2[i][j] = 1 - A[i][j];
            }
        }
    }
}

// Hàm chọn ma trận Alpha từ 1 trong 2 cách tính, từ đó xác định ma trận beta
void chooseMatrix(int choose){
    createSL();
    switch (choose) {
        case 1:
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    AC[i][j] = A1[i][j];
                }
                BS[i] = - B[i];
            }
            break;
        case 2:
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    AC[i][j] = A2[i][j];
                }
                BS[i] = B[i];
            }
    }
}

// Hàm trả về chuẩn của ma trận alpha, 1 là chuẩn 1(chuẩn cột), 2 là chuẩn 2(chuẩn uclid), 3 là chuẩn vô cùng(chuẩn hàng).
float getNormMatrix(int choose){
    float norm, max, temp;
    switch (choose) {
        case 1:
            max = 0;
            for (int i = 1; i <= n; ++i) {
                temp = 0;
                for (int j = 1; j <= n; ++j) {
                    temp = temp + fabs(AC[j][i]);
                }
                if (temp >= max) {
                    max = temp;
                }
            }
            norm = max;
            break;
        case 2:
            temp = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    temp = temp + pow(fabs(AC[i][j]),2);
                }
            }
            norm = sqrt(temp);
            break;
        case 3:
            max = 0;
            for (int i = 1; i <= n; ++i) {
                temp = 0;
                for (int j = 1; j <= n; ++j) {
                    temp = temp + fabs(AC[i][j]);
                }
                if (temp >= max) {
                    max = temp;
                }
            }
            norm = max;
            break;
    }
    return norm;
}

// Hàm trả về chuẩn của vector, 1 là chuẩn tuyệt đối, 2 là chuẩn euclid, 3 là chuẩn cực đại.
float getNormVector(int choose){
    float norm, max = 0, temp = 0;
    switch (choose) {
        case 1:
            for (int i = 1; i <= n; ++i) {
                temp = temp + fabs(XI[i]);
            }
            norm = temp;
            break;
        case 2:
            for (int i = 1; i <= n; ++i) {
                if (fabs(XI[i]) >= max){
                    max = fabs(XI[i]);
                }
            }
            norm = max;
            break;
        case 3:
            temp = 0;
            for (int i = 1; i <= n; ++i) {
                temp = temp + pow(fabs(XI[i]),2);
            }
            norm = sqrt(temp);
            break;
    }
    return norm;
}

// Hàm thực hiện lặp đơn, nMC: normMatrixCheck, nMI: normMatrixIndex
void singleLoop(){
    float nMC,saiSo,XC[10],XC1[10];
    int nMI = 0;
    chooseMatrix(1);
    for (int i = 1; i <= 3; ++i) {
        nMC = getNormMatrix(i);
        if (nMC < 1){
            nMI = i;
            break;
        }
    }
    if (nMI == 0){
        chooseMatrix(2);
        for (int i = 1; i <= 3; ++i) {
            nMC = getNormMatrix(i);
            printf("nmc = %f\n",nMC);
            if (nMC < 1){
                nMI = i;
                break;
            }
        }
        if (nMI == 0){
            printf("Err, norm of matrix is greater than 1!!");
        }
    }
    saiSo = getNormMatrix(nMI) / (1 - getNormMatrix(nMI));
    for (int i = 1; i <= n; ++i) {
        XC[i] = BS[i];
    }
    while (saiSo >= esl){
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                XC1[i] = AC[i][j] * XC[j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            XI[i] = XC1[i] - XC[i];
        }
        for (int i = 1; i <= n; ++i) {
            XC[i] = XC1[i];
        }
        saiSo = getNormVector(2);
        printf("%f\n",saiSo);
    }
    for (int i = 1; i <= n; ++i) {
        X[i] = XC[i];
    }

}
#endif //MYGAUSS_SINGLELOOP_H
