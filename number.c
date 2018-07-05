#include "number.h"
#include "stack.h"

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
