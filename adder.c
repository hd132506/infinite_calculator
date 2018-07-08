#include <stdio.h>
#include <string.h>
#include "number.h"
#include "stack.h"

Number* positive_add(Number *n1, Number *n2) {
    Number* result = init_number();
    Stack *s1 = init_stack(), *s2 = init_stack();
    Stack *res_stack = init_stack();

    // process decimal part
    int carry = 0, len_n1 = strlen(n1->decimal_part), len_n2 = strlen(n2->decimal_part);
    for(int i = 0; i < len_n1; i++)
        push(s1, (n1->decimal_part)[i] - '0');
    for(int i = 0; i < len_n2; i++)
        push(s2, (n2->decimal_part)[i] - '0');
    for(int i = len_n1; i < len_n2; i++) // Tuning length
        push(s1, 0);
    for(int i = len_n2; i < len_n1; i++)
        push(s2, 0);

    int addition;
    while(!empty(s1) || !empty(s2)) {
        addition = pop(s1) + pop(s2) + carry;
        push(res_stack, addition % 10);
        carry = addition / 10;
    }
    int idx = 0;
    while(!empty(res_stack)) {
        (result->decimal_part)[idx++] = pop(res_stack) + '0';
    }

    // process integer part
    len_n1 = strlen(n1->integer_part), len_n2 = strlen(n2->integer_part);
    for(int i = 0; i < len_n1; i++)
        push(s1, (n1->integer_part)[i] - '0');
    for(int i = 0; i < len_n2; i++)
        push(s2, (n2->integer_part)[i] - '0');
    while(!empty(s1) || !empty(s2)) {
        addition = pop(s1) + pop(s2) + carry;
        push(res_stack, addition % 10);
        carry = addition / 10;
    }
    idx = 0;
    if(carry == 1)
        (result->integer_part)[idx++] = '1';
    while(!empty(res_stack)) {
        (result->integer_part)[idx++] = pop(res_stack) + '0';
    }
    trim(result);
    //문자열 끝 \0넣기
    printf("%s.%s\n", result->integer_part, result->decimal_part);
    return result;
}

int main() {
    Number *n1 = init_number(), *n2 = init_number();
    input_number(n1);
    input_number(n2);
    positive_add(n1, n2);
}
