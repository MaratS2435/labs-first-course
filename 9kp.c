#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Table {
    int key;
    int value;
} tbl;

void Swap(tbl *x, tbl *y) {
    tbl temporary = *x;
    *x = *y;
    *y = temporary;
}

int f;
void Braket(tbl a[], int i) {
    int winner = i;
    int right = 2*i + 2;
    int left = 2*i + 1;
    if (left < f && a[left].key > a[i].key) {
        winner = left;
    }
    if (right < f && a[right].key > a[winner].key) {
        winner = right;
    }
    if (winner != i) {
        Swap(&a[i], &a[winner]);
        Braket(a, winner);
    }
}

void Heap(tbl a[]) {
    int i = (f - 2) / 2;
    while (i >= 0) {
        Braket(a, i--);
    }
}

void Sort(tbl a[], int n) {
    f = n;
    Heap(a);
    while (f != 1) {
        Swap(&a[0], &a[f - 1]);
        --f;
        Braket(a, 0);
    }
}

int Search(tbl a[], int n, int value) {
    int low = 0, high = n - 1, middle;
    while (low <= high) {
        middle = (low + high) / 2;
        if (a[middle].key == value) return a[middle].value;
        if (a[middle].key > value) high = middle - 1;
        else low = middle + 1;
    }
    return -1;
}

void Values(tbl *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i].value);
    }
    printf("\n");
}

void Keys(tbl *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i].key);
    }
    printf("\n");
}

int main(void) {
    tbl a[10] = {};
    int n;
    int key, value;
    printf("Введи количество элементов: ");
    scanf("%d", &n);
    int scanKey, element = -1;
    printf("Введи эелементы: ключ и значение\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &key, &value);
        a[i].key = key;
        a[i].value = value;
    }
    printf("\n");
    printf("Отсортированная таблица\n");
    Sort(a, n);
    Keys(a, n);
    Values(a, n);
    printf("\n");
    int flag = 1;
    while(flag != 2) {
        printf("1.Ввести ключ 2.Выйти\n");
        scanf("%d", &flag);
        if(flag == 1) {
            printf("Введите ключ: ");
            scanf("%d", &scanKey);
            element = Search(a, n, scanKey);
            if (element != -1) printf("%d\n", element);
            else printf("По заданному ключу элемент не найден\n");
        }
    }
    return 0;
}