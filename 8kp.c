#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>



typedef enum 
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    THOUSEND = 1000
} eN;

typedef struct listDoublyConnected
{
    eN key;
    struct listDoublyConnected* before;
    struct listDoublyConnected* after;
} list;




list* Normalize(list* root){
    if ((root -> before) == NULL){
        return root;
    }
    while ((root -> before) != NULL)
    {
        root = root -> before;
    }
    return root;
}

list* Create(list* root, eN key)
{
    list* tmp = malloc(sizeof(list));
    tmp -> key = key;
    tmp -> before = NULL;
    tmp -> after = NULL;
    root = tmp;
    return root;
}

list* AddS(list* root, eN key)
{
    list* tmp = malloc(sizeof(list));
    tmp -> key = key;
    while ((root -> after) != NULL)
    {
        root = root -> after;
    }
    root -> after = tmp;
    tmp -> before = root;
    tmp -> after = NULL;
    return root;
}

list* Add(list* root, eN key, int whatPlace)
{
    list* tmp = malloc(sizeof(list));
    tmp -> key = key;
    root = Normalize(root);
    if (whatPlace == 0){
        tmp -> before = NULL;
        tmp -> after = root;
        root -> before = tmp;
    } else {
        while ((whatPlace - 1) > 0)
        {
            root = root -> after;
            whatPlace -= 1;
        }
        if ((root -> after) == NULL){
            root -> after = tmp;
            tmp -> before = root;
            tmp -> after = NULL;   
        } else {
            root -> after -> before = tmp;
            tmp -> after = root -> after;
            root -> after = tmp;
            tmp -> before = root;
        }
    }
    return root;
}

list* Delete(list* root, int position) {
    root = Normalize(root);
    list* tmp = malloc(sizeof(list));

    while ((position - 1) >= 0)
    {
        root = root -> after;
        position -= 1;
    }
    if (((root -> before) == NULL) &&  ((root -> after) == NULL)){
        list* tmp = malloc(sizeof(list));
        tmp -> before = NULL;
        tmp -> after = NULL;
        tmp -> key = 0;
        printf("LIST DESTROYED\n");
        free(root);
        return tmp;
    } else if ((root -> before) == NULL){
        root -> after -> before = NULL;
        tmp = root -> after;
        free(root);
        return tmp;
    } else if ((root -> after) == NULL){
        root -> before -> after = NULL;
        tmp = root -> before;
        free(root);
        return tmp;
    } else {
        root -> before -> after = root -> after;
        root -> after -> before = root -> before;
        tmp = root -> before;
        return tmp;
    }
    return NULL;
}

list* Print(list* root) {
    root = Normalize(root);
    while ((root -> after) != NULL)
    {
        printf("%d ", root -> key);
        root = root -> after;
    }
    printf("%d\n", root -> key);
}

int Count(list* root){
    root = Normalize(root);
    int counter = 0;
    while ((root -> after) != NULL)
    {
        counter += 1;
        root = root -> after;
    }
    counter += 1;
    return counter;
}


int main()
{
    list* root = NULL;
    root = Create(root, ZERO);
    root = AddS(root, ONE);
    root = AddS(root, TWO);
    root = AddS(root, THREE);
    root = AddS(root, FOUR);
    root = AddS(root, FIVE);
    Print(root);
    root = Add(root, THOUSEND, 0);
    root = Add(root, NINE, 5);
    Print(root);
    printf("Размер %d\n", Count(root));
    root = Delete(root, 0);
    Print(root);
    printf("Размер %d\n", Count(root));
    int k1, k2;
    printf("Введите диапозон мест \n");
    scanf("%d %d", &k1, &k2);
    for(int i = k1; i <= k2; i++){
	root = Delete(root, k1);
	}
    Print(root);
    return 0;
}
