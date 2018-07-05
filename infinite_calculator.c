#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "stack.h"
#define MAX_CIPHER 1000000


/* Functions for calculate*/
void positive_add(Stack* first, Stack* second);

/* input/output */
void input_into_stack(char *num, Stack* s);
void print_stack(Stack *s);

/* dealing with string */
char* trim(char *str);

int main() {
    Stack *first = init_stack(), *second = init_stack();
    char *num1, *num2;
    
    // input_into_stack(num1, first);
    // input_into_stack(num2, second);

    positive_add(first, second);
}



void positive_add(Stack* first, Stack* second) {
    Stack *result = init_stack();
    char carry = 0;
    while(first->size > 0 || second->size > 0) {
        char a = pop(first), b = pop(second);
        push(result, (a+b+carry)%10);
        carry = (a+b+carry) / 10;
    }
    if(carry == 1)
        push(result, 1);

    print_stack(result);
}

void input_into_stack(char *num, Stack* s) {
    num = malloc(MAX_CIPHER * sizeof(char));
    scanf("%s", num);
    num = trim(num);

    int len = strlen(num);
    for(int i = 0; i < len; i++) {
        push(s, num[i] - '0');
    }
}

void print_stack(Stack *s) {
    while (s->size > 0) {
        printf("%d", pop(s));
    }
    printf("\n");
}
