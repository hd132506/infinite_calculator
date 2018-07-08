#include "number.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void trim(Number* n) {
    n->integer_part = trim_integer_part(n->integer_part);
    trim_decimal_part(n->decimal_part);
}

char* trim_integer_part(char* str) {
    return *str != '0' || strlen(str) == 1 ? str : trim_integer_part(str+1);
}

void trim_decimal_part(char* str) {
    int idx = strlen(str) - 1;
    while(str[idx] == '0' && idx > 0) {
        str[idx] = '\0';
        idx--;
    }
}

void input_number(Number* n) {
    char **int_part = &(n->integer_part), **dec_part = &(n->decimal_part);
    *int_part = malloc(MAX_CIPHER);
    *dec_part = malloc(MAX_CIPHER);

    //Initial config
    (*dec_part)[0] = '0'; (*dec_part)[1] = '\0';

    int idx = 0;
    char piece, phase = 1; // phase 1: integer part, phase 2: decimal_part
    while((piece = getchar()) != ' ' && piece != '\n') {
        if(piece == '.') {
            phase = 2;
            idx = 0;
        }
        else if(phase == 1) {
            (*int_part)[idx++] = piece;
        }
        else if(phase == 2) {
            (*dec_part)[idx++] = piece;
        }
    }

    if(**int_part == '-') {
        n->sign = '-';
        n->integer_part++;
    } else {
        n->sign = '+';
    }
    trim(n);
}

void print_number(Number* n) {
    if(n->sign == '-')
        printf("-");
    printf("%s.%s\n",n->integer_part, n->decimal_part);
}


int main() {
    Number *a = malloc(sizeof(Number));

   input_number(a);
   print_number(a);
}
