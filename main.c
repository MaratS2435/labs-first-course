#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "sort.h"

int main() {
    struct stack * stk;
    int len1, len2;
    int elem;
    stk = createStack();
    init(stk);
    printf("Введите число элементов стека первого\n");
    scanf("%d", &len1);
    printf("Введите элементы:");
    for(int i = 0; i < len1; i++) {
        scanf("%d", &elem);
        push(stk, elem);
    }
    printf("Введите число элементов стека второго\n");
    scanf("%d", &len2);
    printf("Введите элементы:");
    for(int i = 0; i < len2; i++) {
        scanf("%d", &elem);
        push(stk, elem);
    }
    print(stk);
    printf("\n");
    int mas[getcount(stk)], n = getcount(stk);
    for(int i = 0; i < len1 + len2; i++) {
        mas[i] = pop(stk);
    }
    sort(mas, 0, n - 1);
    printf("\n");
    for(int i = 0; i < len1 + len2; i++) {
        push(stk, mas[i]);
    }
    print(stk);

    free(stk->data);
    free(stk);
    
    return 0;
}
