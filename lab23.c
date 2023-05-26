#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tree {
    int field;
    struct tree* left;
    struct tree* right;
};

struct tree* Add(struct tree* tree, int father, int son, int* fatherFound) {
    if (tree == NULL) {
        if (*fatherFound == 1) {
            tree = (struct tree*) malloc (sizeof(struct tree));
            tree -> field = son;
            tree -> left =  NULL;
            tree -> right = NULL;
            *fatherFound = 2;
        }
    } else if ((father == tree -> field) && (*fatherFound == 0)) {
        *fatherFound = 1;
        tree -> left = Add(tree -> left, father, son, fatherFound);
    } else if (*fatherFound == 1) {
        tree -> right = Add(tree -> right, father, son, fatherFound);
    } else if (*fatherFound == 0) {
        tree -> left = Add(tree -> left, father, son, fatherFound);
        tree -> right = Add(tree -> right, father, son, fatherFound);
    }
    return (tree);
}

void Print(struct tree* tree, int count) {
    if (tree != NULL) { 
        for (int i = 0; i < count; ++i) {
            printf("-");
        }
        ++count;
        printf("%d\n", tree -> field);
        Print(tree -> left, count);
        --count;
        Print(tree -> right, count);
    }
}

int Calc(struct tree* tree) {
    int cnt = 0;
    if (tree != NULL) {
        cnt++;
        cnt += Calc(tree -> left) + Calc(tree -> right);
    }
    return cnt;
}

int main(void) {
    struct tree* root;
    root = NULL;
    int father, son;
    scanf("%d %d", &father, &son);
    int fatherFound = 1;
    root = Add(root, father, son, &fatherFound);
    while (1) {
        scanf("%d %d", &father, &son);
        if (father == 0 && son == 0) {
            break;
        }
        fatherFound = 0;
        root = Add(root, father, son, &fatherFound);
    }
    Print(root, 0);
    printf("%d\n", Calc(root));
    return 0;
} 
