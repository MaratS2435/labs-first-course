#include <stdio.h>

int main() {
    int n1, m1;
    printf("Введите размер первой матрицы\n");
    scanf("%d %d", &n1, &m1);
    int mas[n1][m1];
    printf("Введите первую матрицу\n");
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m1; j++) {
            scanf("%d", &mas[i][j]);
        }
    }
    int CIP1[n1];
    int PI1[n1 * m1 + 1];
    int YE1[n1 * m1];
    int index = 0;
    for(int i = 0; i < n1; i++) {
        CIP1[i] = index;
        for(int j = 0; j < m1; j++) {
            PI1[index] = j + 1;
            YE1[index] = mas[i][j];
            index++;
        }
    }
    int n2, m2;
    printf("Введите размер вторую матрицы\n");
    scanf("%d %d", &n2, &m2);
    if(m1 != n2) {
        printf("Умножение невозможно\n");
    } else {
        printf("Введите вторую матрицу\n");
        for(int i = 0; i < n2; i++) {
            for(int j = 0; j < m2; j++) {
                scanf("%d", &mas[i][j]);
            }
        }
        int CIP2[n2];
        int PI2[n2 * m2 + 1];
        int YE2[n2 * m2];
        index = 0;
        for(int i = 0; i < n2; i++) {
            CIP2[i] = index;
            for(int j = 0; j < m2; j++) {
                PI2[index] = j + 1;
                YE2[index] = mas[i][j];
                index++;
            }
        }
        int CIPR[n1];
        int PIR[n1 * m2 + 1];
        int YER[n1 * m2];
        int res;
        index = 0;
        int flag = 0;
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < m2; j++) {
                PIR[index] = j + 1;
                res = 0;
                for(int a = 0; a < m1; a++) {
                    res += YE1[m1 * i + a] * YE2[a * m2 + j];
                }
                YER[index] = res;
                if(index % m2 != 0 && YER[index] != 0) {
                    flag = 1;
                }
                index++;
            }
        }
        printf("\n");
        index = 0;
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < m2; j++) {
                printf("%d ", YER[index]);
                index++;
            }
            printf("\n");
        }
        if(flag == 0) {
            printf("Матрица дигональная\n");
        } else {
            printf("Матрица не диагональная\n");
        }

    }
    return 0;
}