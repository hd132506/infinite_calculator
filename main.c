#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main() {
    Stack *first = init_stack(), *second = init_stack();
    char *num1, *num2;
    input_into_stack(num1, first);
    input_into_stack(num2, second);

    positive_add(first, second);
}
