#include "sort.h"

void sort(int* s_arr, int first, int last) {
    int i = first, j = last, x = s_arr[(first + last) / 2];

    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;

        if(i <= j) {
            if (s_arr[i] > s_arr[j]) {
                int s_arr1 = s_arr[i];
                s_arr[i] = s_arr[j];
                s_arr[j] = s_arr1;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        sort(s_arr, i, last);
    if (first < j)
        sort(s_arr, first, j);
}
