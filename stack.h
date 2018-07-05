#include <stdlib.h>

typedef struct Stack {
    struct Node *top;
    int size;
} Stack;

Stack* init_stack();
void push(Stack* s, char data);
char top(Stack* s);
char pop(Stack* s);
