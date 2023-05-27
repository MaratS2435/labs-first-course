#ifndef STACK_H
#define STACK_H

#define Max_Size 1
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

typedef int elem;

struct stack {
    elem *data;
    int size;
    int top;
};

struct stack* createStack();
void resize(struct stack *stack);
void push(struct stack *stack, elem value);
void init(struct stack * stk);
int getcount(struct stack *stk);
int empty(struct stack *stk);
void print(struct stack *stk);
int pop(struct stack *stk);

#endif
