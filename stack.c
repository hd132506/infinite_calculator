#include "node.h"
#include "stack.h"

Stack* init_stack() {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->top = (Node*) malloc(sizeof(Node));
    s->top->next = NULL;
    s->size = 0;
    return s;
}

void push(Stack* s, char data) {
    s->top = make_node(data, s->top);
    s->size++;
}

char top(Stack* s) {
    return s->top->data;
}

char pop(Stack* s) {
    if(s->size == 0)
        return 0;
    char poppee = s->top->data;
    Node *free_node = s->top;
    s->top = s->top->next;
    s->size--;
    free(free_node);
    return poppee;
}

int empty(Stack* s) {
    return s->size == 0;
}
