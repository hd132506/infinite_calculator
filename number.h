#include <string.h>
#define MAX_CIPHER 100000

typedef struct Number {
    char sign;
    char* integer_part;
    char* decimal_part;
} Number;


void trim(Number* n);
char* trim_integer_part(char* str);
void trim_decimal_part(char* str);

void input_number(Number* n);
void print_number(Number* n);
