#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack* createStack() {
    struct stack *out = NULL;
    out = malloc(sizeof(struct stack));
    if (out == NULL) {
        exit(OUT_OF_MEMORY);
    }
    out->size = Max_Size;
    out->data = malloc(out->size * sizeof(elem));
    if (out->data == NULL) {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out->top = 0;
    return out;
}

void resize(struct stack *stack) {
    stack->size += 1;
    stack->data = realloc(stack->data, stack->size * sizeof(elem));
    if (stack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
}

void push(struct stack *stack, elem value) {
    if (stack->top >= stack->size) {
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
}

void init(struct stack * stk) {
    stk->top = 0;
}

int getcount(struct stack *stk) {
    return stk->top;
}

int empty(struct stack *stk) {
    if(stk->top == 0) {
        return 1;
    }
    return 0;
}

void print(struct stack *stk) {
    int i;
    i = stk->top;
    if(empty(stk) == 1) {
        return;
    }
    while(i > 0) {
        i--;
        printf("%d\n", stk->data[i]);
    }
}

int pop(struct stack *stk) {
    int elem;
    if(stk->top > 0) {
        stk->top--;
        elem = stk->data[stk->top];
        return elem;
    }
    exit(STACK_UNDERFLOW);
}
